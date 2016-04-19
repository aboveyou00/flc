#pragma once
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class OnesComplementExpressionSyntax : public UnaryOperatorExpressionSyntax
        {
        public:
            OnesComplementExpressionSyntax(ExpressionSyntax *expr);
            ~OnesComplementExpressionSyntax();

            op::UnaryOperator *getUnaryOperator() override;
            std::string getOperatorSymbol() override;
        };
    }
}
