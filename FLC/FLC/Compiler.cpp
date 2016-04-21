#include "stdafx.h"
#include <fstream>
#include <sstream>

#include "Compiler.h"

#include "Tokenizer.h"
#include "ErrorToken.h"
#include "EndOfFileToken.h"

#include "ExpressionSyntaxFactory.h"

#include "PopInstr.h"

namespace flc
{
    Compiler::Compiler()
    {
    }
    Compiler::~Compiler()
    {
        for (size_t q = 0; q < sourceFiles.size(); q++)
        {
            auto toks = sourceFiles[q];
            for (size_t w = 0; w < toks->size(); w++)
            {
                auto tok = toks->at(w);
                delete tok;
            }
            toks->clear();
            delete toks;
        }
        sourceFiles.clear();
    }

    bool Compiler::tryAddSource(string source, string path)
    {
        istringstream stream(source);
        return tryAddSource(&stream, path);
    }
    bool Compiler::tryAddSource(istream *source, string path)
    {
        tokens::Tokenizer tokenizer;
        vector<tokens::Token*>* toks = tokenizer.tokenize(source);
        sourceFiles.push_back(toks);
        //TODO: Keep path information stored with tokens, for better errors later

        bool hasError = false;
        for (auto tok : *toks)
        {
            auto err = dynamic_cast<tokens::ErrorToken*>(tok);
            if (err != nullptr)
            {
                hasError = true;
                //TODO: get line number and character position
                reportError(err->getError(), path);
            }
        }

        return !hasError;
    }
    bool Compiler::tryAddSourceFile(string path)
    {
        ifstream stream(path); //ifstream::in
        if (!stream.is_open()) return false;
        return tryAddSource((istream*)&stream, path);
    }

    bool Compiler::tryCompile()
    {
        if (!assertValidTokens()) return false;
        if (sourceFiles.size() == 0)
        {
            reportError("Cannot compile until you add a source file.");
            return false;
        }
        else if (sourceFiles.size() != 1)
        {
            reportNotImplemented("Cannot compile multiple source files.");
            return false;
        }

        syntax::factory::ExpressionSyntaxFactory exprFactory;

        auto toks = sourceFiles.at(0);
        int pos = 0;
        vector<syntax::ExpressionSyntax*> program;
        while (pos < (int)toks->size() && dynamic_cast<tokens::EndOfFileToken*>(toks->at(pos)) == nullptr)
        {
            syntax::ExpressionSyntax *expr;
            if (!exprFactory.tryParseSyntax(toks, pos, expr))
            {
                //TODO: provide context
                reportError("Could not parse expression.");
                break;
                //return false;
            }
            program.push_back(expr);
        }



        types::NameResolutionContextStack ctx;
        for (auto expr : program)
        {
            expr->registerNames(&ctx);
        }
        for (auto expr : program)
        {
            expr->resolveNames(&ctx);
        }

        for (auto expr : program)
        {
            expr->resolveTypes(&ctx);
        }



        for (auto expr : program)
        {
            auto exprType = expr->getExpressionType();
            cout << expr->toString() << " // ";
            if (exprType != nullptr) cout << exprType->getQualifiedName();
            else cout << "???";
            cout << endl;

            if (exprType == nullptr)
            {
                cout << "Cannot emit instructions - expression type could not be resolved." << endl;
                continue;
            }

            emit::MethodBody method;
            expr->emit(&ctx, &method);
            if (!exprType->isVoid()) method.emit(new emit::PopInstr());
            cout << method.toString();
            method.deleteInstructions();

            cout << endl << endl;
        }

        for (auto expr : program)
            delete expr;
        program.clear();

        reportNotImplemented("Compiler::tryCompile");
        return false;
    }
    bool Compiler::assertValidTokens()
    {
        for (auto toks : sourceFiles)
        {
            for (auto tok : *toks)
            {
                auto err = dynamic_cast<tokens::ErrorToken*>(tok);
                if (err != nullptr)
                {
                    reportError("Cannot compile when tokenizer fails to tokenize correctly. There are syntax errors in your code.");
                    return false;
                }
            }
            auto eof = dynamic_cast<tokens::EndOfFileToken*>(toks->at(toks->size() - 1));
            if (eof == nullptr)
            {
                reportError("Cannot compile when tokenizer fails to tokenize correctly. Missing EOF token.");
                return false;
            }
        }
        return true;
    }
}
