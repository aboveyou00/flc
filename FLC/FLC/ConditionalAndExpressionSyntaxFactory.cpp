#include "stdafx.h"
#include "ConditionalAndExpressionSyntax.h"
#include "ConditionalAndExpressionSyntaxFactory.h"
#include "InclusiveOrExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ConditionalAndExpressionSyntaxFactory::ConditionalAndExpressionSyntaxFactory()
            {
            }
            ConditionalAndExpressionSyntaxFactory::~ConditionalAndExpressionSyntaxFactory()
            {
            }

            bool ConditionalAndExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                InclusiveOrExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool ConditionalAndExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("&&"))
                {
                    InclusiveOrExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new ConditionalAndExpressionSyntax(result, rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
