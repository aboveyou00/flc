#include "stdafx.h"
#include "EqualityExpressionSyntax.h"
#include "EqualityExpressionSyntaxFactory.h"
#include "RelationalExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            EqualityExpressionSyntaxFactory::EqualityExpressionSyntaxFactory()
            {
            }
            EqualityExpressionSyntaxFactory::~EqualityExpressionSyntaxFactory()
            {
            }

            bool EqualityExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                RelationalExpressionSyntaxFactory relationalFactory;
                if (!relationalFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("==") || toks->at(pos)->isSymbol("!="))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *equality = nullptr;
                    if (!tryParseSyntax(toks, p2, equality))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new EqualityExpressionSyntax(result, toks->at(pos)->toString(), equality);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
