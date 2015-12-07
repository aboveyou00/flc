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
                InclusiveOrExpressionSyntaxFactory inclusiveOrFactory;
                if (!inclusiveOrFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("&&"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *conditionalAnd = nullptr;
                    if (!tryParseSyntax(toks, p2, conditionalAnd))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        return false;
                    }
                    result = new ConditionalAndExpressionSyntax(result, conditionalAnd);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
