#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class NegateExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            NegateExpressionSyntax(ExpressionSyntax *expr);
            ~NegateExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
