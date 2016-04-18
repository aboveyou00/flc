#include "stdafx.h"
#include "WhileExpressionSyntax.h"
#include "WhileExpressionSyntaxFactory.h"
#include "ExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            WhileExpressionSyntaxFactory::WhileExpressionSyntaxFactory()
            {
            }
            WhileExpressionSyntaxFactory::~WhileExpressionSyntaxFactory()
            {
            }

            bool WhileExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                bool isWhile = toks->at(pos)->isKeyword("while");
                if (!isWhile && !toks->at(pos)->isKeyword("until")) return false;

                int p = pos + 1;
                if (!toks->at(p++)->isSymbol("(")) return false;

                ExpressionSyntaxFactory exprFactory;
                ExpressionSyntax *cond, *whileExpr;

                if (!exprFactory.tryParseSyntax(toks, p, cond)) return false;

                if (!toks->at(p++)->isSymbol(")") || !exprFactory.tryParseSyntax(toks, p, whileExpr))
                {
                    delete cond; //Clean up partial expression
                    return false;
                }

                pos = p;
                result = new WhileExpressionSyntax(cond, whileExpr, isWhile);
                return true;
            }
        }
    }
}
