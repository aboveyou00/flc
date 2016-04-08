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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
