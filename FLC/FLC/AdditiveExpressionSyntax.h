#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class AdditiveOperator
        {
            ErrorState = -1,
            Add = 0,
            Subtract = 1
        };

        class AdditiveExpressionSyntax : public ExpressionSyntax
        {
        public:
            AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~AdditiveExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            AdditiveOperator getOperator();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            AdditiveOperator _op;
            
            types::MethodOverload *_overload = nullptr;
        };
    }
}
