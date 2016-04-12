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

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            AssignmentOperator getOperator();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left, *_right;
            AssignmentOperator _op;
        };
    }
}
