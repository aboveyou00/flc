#pragma once
#include "ExpressionSyntax.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace syntax
    {
        class UnaryOperatorExpressionSyntax : public ExpressionSyntax
        {
        public:
            UnaryOperatorExpressionSyntax(ExpressionSyntax *expr);
            ~UnaryOperatorExpressionSyntax();

            ExpressionSyntax* getOperand();

            virtual op::UnaryOperator *getUnaryOperator() = 0;
            virtual std::string getOperatorSymbol() = 0;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_expr = nullptr;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
