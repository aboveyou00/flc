#pragma once
#include "UnaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class UnaryOperator
        {
            ErrorState = -1,
            Plus = 0,
            Minus = 1,
            Not = 2,
            Complement = 3,
            PreIncrement = 4,
            PreDecrement = 5
        };

        class UnaryExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            UnaryExpressionSyntax(string op, ExpressionSyntax* expr);
            ~UnaryExpressionSyntax();

            int getPrecedence() override;

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;

            UnaryOperator getOperator();

        private:
            UnaryOperator _op;
        };
    }
}
