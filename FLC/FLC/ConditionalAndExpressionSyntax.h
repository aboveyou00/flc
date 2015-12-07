#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ConditionalAndExpressionSyntax : public ExpressionSyntax
        {
        public:
            ConditionalAndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~ConditionalAndExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
