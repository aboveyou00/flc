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

            int getPrecedence() override;

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
        };
    }
}
