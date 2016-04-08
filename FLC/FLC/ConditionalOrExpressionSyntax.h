#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ConditionalOrExpressionSyntax : public ExpressionSyntax
        {
        public:
            ConditionalOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~ConditionalOrExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
