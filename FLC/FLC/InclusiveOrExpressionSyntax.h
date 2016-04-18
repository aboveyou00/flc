#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        class InclusiveOrExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~InclusiveOrExpressionSyntax();

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
