#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class PreIncrementExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            PreIncrementExpressionSyntax(ExpressionSyntax *expr);
            ~PreIncrementExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
