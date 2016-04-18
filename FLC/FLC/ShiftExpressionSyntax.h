#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class ShiftOperator
        {
            ErrorState = -1,
            Left = 0,
            Right = 1
        };

        class ShiftExpressionSyntax : public ExpressionSyntax
        {
        public:
            ShiftExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~ShiftExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            ShiftOperator getOperator();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            ShiftOperator _op;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
