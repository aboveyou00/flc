#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

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

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
