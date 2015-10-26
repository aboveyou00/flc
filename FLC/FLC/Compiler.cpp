#include "stdafx.h"
#include "Compiler.h"
#include "Tokenizer.h"
#include "ErrorToken.h"
#include "ExpressionSyntaxFactory.h"
#include <fstream>
#include <sstream>

namespace flc
{
    Compiler::Compiler()
    {
    }
    Compiler::~Compiler()
    {
    }

    bool Compiler::tryAddSource(string source, string path)
    {
        istringstream stream(source);
        return tryAddSource(&stream);
    }
    bool Compiler::tryAddSource(istream *source, string path)
    {
        tokens::Tokenizer tokenizer;
        vector<tokens::Token*>* toks = tokenizer.tokenize(source);
        sourceFiles.push_back(toks);

        bool hasError = false;
        for (auto tok : *toks)
        {
            auto err = dynamic_cast<tokens::ErrorToken*>(tok);
            if (err != NULL)
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
        return Compiler::tryAddSource((istream*)&stream);
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

        syntax::factory::ExpressionSyntaxFactory factory;



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
                if (err != NULL)
                {
                    reportError("Cannot compile when tokenizer fails to tokenize correctly. There are syntax errors in your code.");
                    return false;
                }
            }
            //TODO: Check if last token is EOF token
        }
        return true;
    }
}
