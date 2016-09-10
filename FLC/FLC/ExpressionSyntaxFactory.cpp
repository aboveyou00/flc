#include "stdafx.h"
#include "Token.h"

#include "ExpressionSyntax.h"
#include "AssignmentExpressionSyntax.h"

#include "ExpressionSyntaxFactory.h"
#include "TernaryExpressionSyntaxFactory.h"
#include "IfExpressionSyntaxFactory.h"
#include "WhileExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ExpressionSyntaxFactory::ExpressionSyntaxFactory()
            {
            }
            ExpressionSyntaxFactory::~ExpressionSyntaxFactory()
            {
            }

            bool ExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (!tryParseFirstSyntax(toks, pos, result)) return false;
                while (tryParseNextSyntax(result, toks, pos, result)) {}
                return true;
            }

            bool ExpressionSyntaxFactory::tryParseFirstSyntax(vector<flc::tokens::Token*>* toks, int & pos, ExpressionSyntax*& result)
            {
                IfExpressionSyntaxFactory ifFactory;
                if (ifFactory.tryParseSyntax(toks, pos, result)) return true;
                WhileExpressionSyntaxFactory whileFactory;
                if (whileFactory.tryParseSyntax(toks, pos, result)) return true;
                TernaryExpressionSyntaxFactory ternaryFactory;
                if (ternaryFactory.tryParseSyntax(toks, pos, result)) return true;
                return false;
            }
            bool extractAssignmentSymbol(vector<flc::tokens::Token*>* toks, int& pos, string& result);
            bool ExpressionSyntaxFactory::tryParseNextSyntax(ExpressionSyntax* term, vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                int p = pos;
                string assignSym;
                if (term->isQualifiedName() && extractAssignmentSymbol(toks, p, assignSym))
                {
                    if (!tryParseSyntax(toks, p, result)) return false;
                    result = new AssignmentExpressionSyntax(term, assignSym, result);
                    pos = p;
                    return true;
                }
                return false;
            }

            bool extractAssignmentSymbol(vector<flc::tokens::Token*>* toks, int& pos, string& result)
            {
                static vector<string>* assignSyms = new vector<string>();
                if (assignSyms->size() == 0)
                {
                    assignSyms->push_back("=");
                    assignSyms->push_back("+=");
                    assignSyms->push_back("-=");
                    assignSyms->push_back("*=");
                    assignSyms->push_back("/=");
                    assignSyms->push_back("%=");
                    assignSyms->push_back("|=");
                    assignSyms->push_back("&=");
                    assignSyms->push_back("^=");
                    assignSyms->push_back("<<=");
                }

                auto tok = toks->at(pos);
                for (size_t q = 0; q < assignSyms->size(); q++)
                {
                    if (tok->isSymbol(assignSyms->at(q)))
                    {
                        pos++;
                        result = assignSyms->at(q);
                        return true;
                    }
                }

                //Special case: >>=, because it is two different tokens, > and >=
                if (tok->isSymbol(">") && toks->at(pos + 1)->isSymbol(">=") && tok->getStartPosition() + 1 == toks->at(pos + 1)->getStartPosition())
                {
                    pos += 2;
                    result = ">>=";
                    return true;
                }

                return false;
            }
        }
    }
}
