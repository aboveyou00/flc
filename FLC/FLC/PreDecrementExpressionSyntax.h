#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class PreDecrementExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            PreDecrementExpressionSyntax(ExpressionSyntax *expr);
            ~PreDecrementExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
