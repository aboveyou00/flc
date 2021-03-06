#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        class ExclusiveOrExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            ExclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~ExclusiveOrExpressionSyntax();

            int getPrecedence() override;

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
