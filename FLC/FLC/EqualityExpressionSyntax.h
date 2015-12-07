#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        enum class EqualityOperator
        {
            ErrorState = -1,
            Equals = 0,
            NotEquals = 1
        };

        class EqualityExpressionSyntax : public ExpressionSyntax
        {
        public:
            EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~EqualityExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            EqualityOperator getOperator();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
            EqualityOperator _op;
        };
    }
}
