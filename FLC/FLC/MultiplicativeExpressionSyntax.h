#pragma once
#include "ExpressionSyntax.h"

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

        class MultiplicativeExpressionSyntax : public ExpressionSyntax
        {
        public:
            MultiplicativeExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~MultiplicativeExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            MultiplicativeOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
            MultiplicativeOperator _op;
        };
    }
}
