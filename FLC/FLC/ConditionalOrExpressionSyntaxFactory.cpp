#include "stdafx.h"
#include "ConditionalOrExpressionSyntax.h"
#include "ConditionalOrExpressionSyntaxFactory.h"
#include "ConditionalAndExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ConditionalOrExpressionSyntaxFactory::ConditionalOrExpressionSyntaxFactory()
            {
            }
            ConditionalOrExpressionSyntaxFactory::~ConditionalOrExpressionSyntaxFactory()
            {
            }

            bool ConditionalOrExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                ConditionalAndExpressionSyntaxFactory conditionalAndFactory;
                if (!conditionalAndFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("||"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *conditionalOr = nullptr;
                    if (!tryParseSyntax(toks, p2, conditionalOr))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new ConditionalOrExpressionSyntax(result, conditionalOr);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
