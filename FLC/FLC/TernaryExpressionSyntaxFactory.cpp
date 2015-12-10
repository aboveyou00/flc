#include "stdafx.h"
#include "TernaryExpressionSyntax.h"
#include "TernaryExpressionSyntaxFactory.h"
#include "ConditionalOrExpressionSyntaxFactory.h"
#include "ExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            TernaryExpressionSyntaxFactory::TernaryExpressionSyntaxFactory()
            {
            }
            TernaryExpressionSyntaxFactory::~TernaryExpressionSyntaxFactory()
            {
            }

            bool TernaryExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                ConditionalOrExpressionSyntaxFactory conditionalOrFactory;
                if (!conditionalOrFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("?"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntaxFactory expressionFactory;
                    ExpressionSyntax *iftrue = nullptr, *iffalse = nullptr;
                    if (!expressionFactory.tryParseSyntax(toks, p2, iftrue) ||
                        !toks->at(p2++)->isSymbol(":") ||
                        !expressionFactory.tryParseSyntax(toks, p2, iffalse))
                    {
                        //TODO: provide more context
                        reportError("Invalid ternary expression: " + result->toString() + toks->at(pos)->toString());
                        return false;
                    }
                    result = new TernaryExpressionSyntax(result, iftrue, iffalse);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
