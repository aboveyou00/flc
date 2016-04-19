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
                AndExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool ExclusiveOrExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("^"))
                {
                    AndExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new ExclusiveOrExpressionSyntax(result, rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
