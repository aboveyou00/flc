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
                ConditionalAndExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool ConditionalOrExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("||"))
                {
                    ConditionalAndExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new ConditionalOrExpressionSyntax(result, rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
