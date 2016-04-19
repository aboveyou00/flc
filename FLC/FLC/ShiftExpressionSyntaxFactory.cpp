#include "stdafx.h"
#include "ShiftExpressionSyntax.h"
#include "ShiftExpressionSyntaxFactory.h"
#include "AdditiveExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ShiftExpressionSyntaxFactory::ShiftExpressionSyntaxFactory()
            {
            }
            ShiftExpressionSyntaxFactory::~ShiftExpressionSyntaxFactory()
            {
            }

            bool ShiftExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                AdditiveExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool ShiftExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("<<") ||
                    (toks->at(pos)->isSymbol(">") && toks->at(pos + 1)->isSymbol(">") &&
                      toks->at(pos + 1)->getStartPosition() == toks->at(pos)->getStartPosition() + 1))
                {
                    AdditiveExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + (toks->at(pos)->isSymbol("<<") ? 1 : 2);
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new ShiftExpressionSyntax(result, toks->at(pos)->isSymbol("<<") ? "<<" : ">>", rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
