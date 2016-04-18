#pragma once
#include "BinaryOperatorExpressionSyntax.h"
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

        class RelationalExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right);
            ~RelationalExpressionSyntax();

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;

            RelationalOperator getOperator();

        private:
            RelationalOperator _op;
        };
    }
}
