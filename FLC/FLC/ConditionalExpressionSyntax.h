#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace emit
    {
        class BranchInstr;
    }

    namespace types
    {
        class MethodOverload;
        class NameResolutionContextStack;
        class RuntimeType;
    }

    namespace syntax
    {
        class ConditionalExpressionSyntax : public ExpressionSyntax
        {
        public:
            ConditionalExpressionSyntax(ExpressionSyntax *left, ExpressionSyntax *right);
            ~ConditionalExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

            virtual std::string getOperatorSymbol() = 0;

        protected:
            virtual emit::BranchInstr *createBranchInstr() = 0;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            types::MethodOverload *_castLeft = nullptr,
                                  *_castRight = nullptr;
        };
    }
}
