#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class MultiplicativeOperator
        {
            ErrorState = -1,
            Multiply = 0,
            Divide = 1,
            Remainder = 2
        };

        class MultiplicativeExpressionSyntax : public ExpressionSyntax
        {
        public:
            MultiplicativeExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~MultiplicativeExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            MultiplicativeOperator getOperator();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            MultiplicativeOperator _op;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
