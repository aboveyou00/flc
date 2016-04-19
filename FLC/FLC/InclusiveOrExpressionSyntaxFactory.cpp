#include "stdafx.h"
#include "InclusiveOrExpressionSyntax.h"
#include "InclusiveOrExpressionSyntaxFactory.h"
#include "ExclusiveOrExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            InclusiveOrExpressionSyntaxFactory::InclusiveOrExpressionSyntaxFactory()
            {
            }
            InclusiveOrExpressionSyntaxFactory::~InclusiveOrExpressionSyntaxFactory()
            {
            }

            bool InclusiveOrExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                ExclusiveOrExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool InclusiveOrExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("|"))
                {
                    ExclusiveOrExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new InclusiveOrExpressionSyntax(result, rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
