#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class AdditiveOperator
        {
            ErrorState = -1,
            Add = 0,
            Subtract = 1
        };

        class AdditiveExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~AdditiveExpressionSyntax();

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;

            AdditiveOperator getOperator();

        private:
            AdditiveOperator _op;
        };
    }
}
