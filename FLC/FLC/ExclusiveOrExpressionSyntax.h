#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

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

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
