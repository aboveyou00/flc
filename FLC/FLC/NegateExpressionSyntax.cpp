#include "stdafx.h"
#include "NegateExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        NegateExpressionSyntax::NegateExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        NegateExpressionSyntax::~NegateExpressionSyntax()
        {
        }

        op::UnaryOperator *NegateExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::negation();
        }
        std::string NegateExpressionSyntax::getOperatorSymbol()
        {
            return  "-";
        }
    }
}
