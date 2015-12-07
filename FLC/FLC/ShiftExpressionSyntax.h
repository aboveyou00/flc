#pragma once
#include "ExpressionSyntax.h"

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

        class ShiftExpressionSyntax : public ExpressionSyntax
        {
        public:
            ShiftExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~ShiftExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            ShiftOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
            ShiftOperator _op;
        };
    }
}
