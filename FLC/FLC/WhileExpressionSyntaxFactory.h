#pragma once
#include <vector>
#include "Token.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            class WhileExpressionSyntaxFactory
            {
            public:
                WhileExpressionSyntaxFactory();
                ~WhileExpressionSyntaxFactory();

                virtual bool tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
            };
        }
    }
}
