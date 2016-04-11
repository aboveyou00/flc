#pragma once
#include <vector>
#include "Token.h"
#include "IfExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            class IfExpressionSyntaxFactory
            {
            public:
                IfExpressionSyntaxFactory();
                ~IfExpressionSyntaxFactory();

                virtual bool tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
            };
        }
    }
}
