#pragma once
#include "ExpressionSyntax.h"

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

        class AdditiveExpressionSyntax : public ExpressionSyntax
        {
        public:
            AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~AdditiveExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            AdditiveOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
            AdditiveOperator _op;
        };
    }
}
