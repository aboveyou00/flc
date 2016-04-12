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

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
