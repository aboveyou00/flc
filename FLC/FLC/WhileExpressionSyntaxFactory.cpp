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
                int p = pos;
                if (!toks->at(p++)->isKeyword("while")) return false;
                if (!toks->at(p++)->isSymbol("(")) return false;

                ExpressionSyntaxFactory exprFactory;
                ExpressionSyntax* cond;
                if (!exprFactory.tryParseSyntax(toks, p, cond)) return false;

                if (!toks->at(p++)->isSymbol(")")) return false;
                ExpressionSyntax* whileExpr;
                if (!exprFactory.tryParseSyntax(toks, p, whileExpr)) return false;

                pos = p;
                result = new WhileExpressionSyntax(cond, whileExpr);
                return true;
            }
        }
    }
}
