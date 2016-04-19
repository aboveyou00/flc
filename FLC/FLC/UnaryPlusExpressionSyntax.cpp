#include "stdafx.h"
#include "UnaryPlusExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        UnaryPlusExpressionSyntax::UnaryPlusExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        UnaryPlusExpressionSyntax::~UnaryPlusExpressionSyntax()
        {
        }

        op::UnaryOperator *UnaryPlusExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::unaryPlus();
        }
        std::string UnaryPlusExpressionSyntax::getOperatorSymbol()
        {
            return  "+";
        }
    }
}
