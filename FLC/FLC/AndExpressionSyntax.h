#pragma once
#include "BinaryOperatorExpressionSyntax.h"
#include "MethodOverload.h"

namespace flc
{
    namespace syntax
    {
        class AndExpressionSyntax : public BinaryOperatorExpressionSyntax
        {
        public:
            AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~AndExpressionSyntax();

            int getPrecedence() override;

            op::BinaryOperator *getBinaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
