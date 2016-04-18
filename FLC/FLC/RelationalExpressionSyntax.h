#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class RelationalOperator
        {
            ErrorState = -1,
            LessThan = 0,
            GreaterThan = 1,
            LessThanOrEqualTo = 2,
            GreaterThanOrEqualTo = 3
        };

        class RelationalExpressionSyntax : public ExpressionSyntax
        {
        public:
            RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~RelationalExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            RelationalOperator getOperator();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            RelationalOperator _op;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
