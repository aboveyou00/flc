#pragma once
#include "ExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        class BinaryOperatorExpressionSyntax : public ExpressionSyntax
        {
        public:
            BinaryOperatorExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~BinaryOperatorExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual op::BinaryOperator *getBinaryOperator() = 0;
            virtual std::string getOperatorSymbol() = 0;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            types::MethodOverload *_overload = nullptr,
                                  *_castLeft = nullptr,
                                  *_castRight = nullptr;
        };
    }
}
