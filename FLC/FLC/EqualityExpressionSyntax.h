#pragma once
#include "BinaryOperatorExpressionSyntax.h"
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

        class EqualityExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~EqualityExpressionSyntax();

            int getPrecedence() override;

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;

            EqualityOperator getOperator();

        private:
            EqualityOperator _op;
        };
    }
}
