#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class LogicalNotExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            LogicalNotExpressionSyntax(ExpressionSyntax *expr);
            ~LogicalNotExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
