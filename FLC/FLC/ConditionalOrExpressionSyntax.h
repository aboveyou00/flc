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

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
        };
    }
}
