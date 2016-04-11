#include "stdafx.h"
#include "IfExpressionSyntax.h"
#include "IfExpressionSyntaxFactory.h"
#include "ExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            IfExpressionSyntaxFactory::IfExpressionSyntaxFactory()
            {
            }
            IfExpressionSyntaxFactory::~IfExpressionSyntaxFactory()
            {
            }

            bool IfExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                int p = pos;
                if (!toks->at(p++)->isKeyword("if")) return false;
                if (!toks->at(p++)->isSymbol("(")) return false;

                ExpressionSyntaxFactory exprFactory;
                ExpressionSyntax* cond;
                if (!exprFactory.tryParseSyntax(toks, p, cond)) return false;

                if (!toks->at(p++)->isSymbol(")")) return false;
                ExpressionSyntax* ifExpr;
                if (!exprFactory.tryParseSyntax(toks, p, ifExpr)) return false;

                pos = p;
                ExpressionSyntax* elseExpr = nullptr;
                if (toks->at(p++)->isKeyword("else") && exprFactory.tryParseSyntax(toks, p, elseExpr)) pos = p;

                result = new IfExpressionSyntax(cond, ifExpr, elseExpr);
                return true;
            }
        }
    }
}
