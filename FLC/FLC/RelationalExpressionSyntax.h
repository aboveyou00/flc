#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        enum class RelationalOperator
        {
            ErrorState = -1,
            LessThan = 0,
            GreaterThan = 1,
            LessThanOrEqualTo = 2,
            GreaterThanOrEqualTo = 3
        };

        class RelationalExpressionSyntax : public ExpressionSyntax
        {
        public:
            RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~RelationalExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            RelationalOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
            RelationalOperator _op;
        };
    }
}
