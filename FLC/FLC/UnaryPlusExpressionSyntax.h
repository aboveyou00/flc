#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class UnaryPlusExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            UnaryPlusExpressionSyntax(ExpressionSyntax *expr);
            ~UnaryPlusExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
