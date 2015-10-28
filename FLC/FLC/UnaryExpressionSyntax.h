#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        enum class UnaryOperator
        {
            ErrorState = -1,
            Plus = 0,
            Minus = 1,
            Not = 2
        };

        class UnaryExpressionSyntax : public ExpressionSyntax
        {
        public:
            UnaryExpressionSyntax(string op, ExpressionSyntax* expr);
            ~UnaryExpressionSyntax();

            UnaryOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax* _expr;
            UnaryOperator _op;
        };
    }
}
