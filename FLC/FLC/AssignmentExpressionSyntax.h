#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        enum class AssignmentOperator
        {
            ErrorState = -1,
            None = 0,
            Add = 1,
            Subtract = 2,
            Multiply = 3,
            Divide = 4,
            Remainder = 5,
            Or = 6,
            And = 7,
            Not = 8,
            ShiftLeft = 9,
            ShiftRight = 10
        };

        class AssignmentExpressionSyntax : public ExpressionSyntax
        {
        public:
            AssignmentExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~AssignmentExpressionSyntax();

            int getPrecedence() override;

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            AssignmentOperator getOperator();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            AssignmentOperator _op;
        };
    }
}
