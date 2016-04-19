#include "stdafx.h"
#include "PreDecrementExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        PreDecrementExpressionSyntax::PreDecrementExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        PreDecrementExpressionSyntax::~PreDecrementExpressionSyntax()
        {
        }

        op::UnaryOperator *PreDecrementExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::decrement();
        }
        std::string PreDecrementExpressionSyntax::getOperatorSymbol()
        {
            return  "--";
        }
    }
}
