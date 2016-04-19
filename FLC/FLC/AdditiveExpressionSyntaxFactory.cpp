#include "stdafx.h"
#include "AdditiveExpressionSyntax.h"
#include "AdditiveExpressionSyntaxFactory.h"
#include "MultiplicativeExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            AdditiveExpressionSyntaxFactory::AdditiveExpressionSyntaxFactory()
            {
            }
            AdditiveExpressionSyntaxFactory::~AdditiveExpressionSyntaxFactory()
            {
            }

            bool AdditiveExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                MultiplicativeExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool AdditiveExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("+") || toks->at(pos)->isSymbol("-"))
                {
                    MultiplicativeExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new AdditiveExpressionSyntax(result, toks->at(pos)->toString(), rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
