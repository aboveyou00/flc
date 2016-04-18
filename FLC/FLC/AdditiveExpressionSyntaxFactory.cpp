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
                MultiplicativeExpressionSyntaxFactory multiplicativeFactory;
                if (!multiplicativeFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("+") || toks->at(pos)->isSymbol("-"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *additive = nullptr;
                    if (!tryParseSyntax(toks, p2, additive))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new AdditiveExpressionSyntax(result, toks->at(pos)->toString(), additive);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
