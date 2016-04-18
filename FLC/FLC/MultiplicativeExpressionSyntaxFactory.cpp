#include "stdafx.h"
#include "MultiplicativeExpressionSyntax.h"
#include "MultiplicativeExpressionSyntaxFactory.h"
#include "UnaryExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            MultiplicativeExpressionSyntaxFactory::MultiplicativeExpressionSyntaxFactory()
            {
            }
            MultiplicativeExpressionSyntaxFactory::~MultiplicativeExpressionSyntaxFactory()
            {
            }

            bool MultiplicativeExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                UnaryExpressionSyntaxFactory unaryFactory;
                if (!unaryFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("*") || toks->at(pos)->isSymbol("/") ||
                    toks->at(pos)->isSymbol("%"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *multiplicative = nullptr;
                    if (!tryParseSyntax(toks, p2, multiplicative))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new MultiplicativeExpressionSyntax(result, toks->at(pos)->toString(), multiplicative);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
