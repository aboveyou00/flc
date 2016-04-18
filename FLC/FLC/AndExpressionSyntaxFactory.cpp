#include "stdafx.h"
#include "AndExpressionSyntax.h"
#include "AndExpressionSyntaxFactory.h"
#include "EqualityExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            AndExpressionSyntaxFactory::AndExpressionSyntaxFactory()
            {
            }
            AndExpressionSyntaxFactory::~AndExpressionSyntaxFactory()
            {
            }

            bool AndExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                EqualityExpressionSyntaxFactory equalityFactory;
                if (!equalityFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("&"))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *andExpr = nullptr;
                    if (!tryParseSyntax(toks, p2, andExpr))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new AndExpressionSyntax(result, andExpr);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
