#include "stdafx.h"
#include "ExclusiveOrExpressionSyntax.h"
#include "ExclusiveOrExpressionSyntaxFactory.h"
#include "AndExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ExclusiveOrExpressionSyntaxFactory::ExclusiveOrExpressionSyntaxFactory()
            {
            }
            ExclusiveOrExpressionSyntaxFactory::~ExclusiveOrExpressionSyntaxFactory()
            {
            }

            bool ExclusiveOrExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                AndExpressionSyntaxFactory andFactory;
                if (!andFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("^"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *exclusiveOr = nullptr;
                    if (!tryParseSyntax(toks, p2, exclusiveOr))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new ExclusiveOrExpressionSyntax(result, exclusiveOr);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
