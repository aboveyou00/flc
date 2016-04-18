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
