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
                ExclusiveOrExpressionSyntaxFactory exclusiveOrFactory;
                if (!exclusiveOrFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("|"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *inclusiveOr = nullptr;
                    if (!tryParseSyntax(toks, p2, inclusiveOr))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        return false;
                    }
                    result = new InclusiveOrExpressionSyntax(result, inclusiveOr);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
