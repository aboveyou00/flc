#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class InclusiveOrExpressionSyntax : public ExpressionSyntax
        {
        public:
            InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~InclusiveOrExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
