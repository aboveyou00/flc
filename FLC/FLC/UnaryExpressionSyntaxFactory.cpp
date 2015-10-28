#include "stdafx.h"
#include <vector>
#include "Token.h"
#include "UnaryExpressionSyntax.h"
#include "UnaryExpressionSyntaxFactory.h"
#include "TermSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            UnaryExpressionSyntaxFactory::UnaryExpressionSyntaxFactory()
            {
            }
            UnaryExpressionSyntaxFactory::~UnaryExpressionSyntaxFactory()
            {
            }

            bool UnaryExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                int p = pos;
                if (toks->at(pos)->isSymbol("+") || toks->at(pos)->isSymbol("-") || toks->at(pos)->isSymbol("!"))
                {
                    int p = pos + 1;
                    if (!tryParseSyntax(toks, p, result)) return false;
                    result = new UnaryExpressionSyntax(toks->at(pos)->toString(), result);
                    pos = p;
                    return true;
                }
                TermSyntaxFactory termFactory;
                return termFactory.tryParseSyntax(toks, pos, result);
            }
        }
    }
}
