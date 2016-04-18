#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        class AndExpressionSyntax : public ExpressionSyntax
        {
        public:
            AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~AndExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
