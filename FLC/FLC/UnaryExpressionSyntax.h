#pragma once
#include "ExpressionSyntax.h"
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

        class UnaryExpressionSyntax : public ExpressionSyntax
        {
        public:
            UnaryExpressionSyntax(string op, ExpressionSyntax* expr);
            ~UnaryExpressionSyntax();

            UnaryOperator getOperator();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_expr = nullptr;
            UnaryOperator _op;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
