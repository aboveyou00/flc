#pragma once
#include "ExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        enum class EqualityOperator
        {
            ErrorState = -1,
            Equals = 0,
            NotEquals = 1
        };

        class EqualityExpressionSyntax : public ExpressionSyntax
        {
        public:
            EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~EqualityExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();
            EqualityOperator getOperator();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left = nullptr,
                             *_right = nullptr;
            EqualityOperator _op;

            types::MethodOverload *_overload = nullptr;
        };
    }
}
