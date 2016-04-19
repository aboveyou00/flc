#include "stdafx.h"
#include "OnesComplementExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        OnesComplementExpressionSyntax::OnesComplementExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        OnesComplementExpressionSyntax::~OnesComplementExpressionSyntax()
        {
        }

        op::UnaryOperator *OnesComplementExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::onesComplement();
        }
        std::string OnesComplementExpressionSyntax::getOperatorSymbol()
        {
            return  "~";
        }
    }
}
