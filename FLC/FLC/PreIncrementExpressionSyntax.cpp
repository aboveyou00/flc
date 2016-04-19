#include "stdafx.h"
#include "PreIncrementExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        PreIncrementExpressionSyntax::PreIncrementExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        PreIncrementExpressionSyntax::~PreIncrementExpressionSyntax()
        {
        }

        op::UnaryOperator *PreIncrementExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::increment();
        }
        std::string PreIncrementExpressionSyntax::getOperatorSymbol()
        {
            return  "++";
        }
    }
}
