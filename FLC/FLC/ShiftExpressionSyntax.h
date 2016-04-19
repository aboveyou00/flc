#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class ShiftOperator
        {
            ErrorState = -1,
            Left = 0,
            Right = 1
        };

        class ShiftExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            ShiftExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~ShiftExpressionSyntax();

            int getPrecedence() override;

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;

            ShiftOperator getOperator();

        private:
            ShiftOperator _op;
        };
    }
}
