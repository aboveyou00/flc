#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ExclusiveOrExpressionSyntax : public ExpressionSyntax
        {
        public:
            ExclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~ExclusiveOrExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
