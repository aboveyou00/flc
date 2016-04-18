#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class MultiplicativeOperator
        {
            ErrorState = -1,
            Multiply = 0,
            Divide = 1,
            Remainder = 2
        };

        class MultiplicativeExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            MultiplicativeExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~MultiplicativeExpressionSyntax();

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;

            MultiplicativeOperator getOperator();

        private:
            MultiplicativeOperator _op;
        };
    }
}
