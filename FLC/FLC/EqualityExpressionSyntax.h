#pragma once
#include "ExpressionSyntax.h"

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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_left, *_right;
            EqualityOperator _op;
        };
    }
}
