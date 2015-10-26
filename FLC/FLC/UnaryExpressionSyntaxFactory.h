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
            class UnaryExpressionSyntaxFactory
            {
            public:
                UnaryExpressionSyntaxFactory();
                ~UnaryExpressionSyntaxFactory();

                virtual bool tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
            };
        }
    }
}
