#pragma once
#include <vector>
#include "Token.h"
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            class AdditiveExpressionSyntaxFactory
            {
            public:
                AdditiveExpressionSyntaxFactory();
                ~AdditiveExpressionSyntaxFactory();

                virtual bool tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
                virtual bool tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
            };
        }
    }
}
