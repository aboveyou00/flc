#include "stdafx.h"
#include "ExclusiveOrExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        ExclusiveOrExpressionSyntax::ExclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
        }
        ExclusiveOrExpressionSyntax::~ExclusiveOrExpressionSyntax()
        {
        }

        int ExclusiveOrExpressionSyntax::getPrecedence()
        {
            return 800;
        }

        op::BinaryOperator *ExclusiveOrExpressionSyntax::getBinaryOperator()
        {
            return op::Operator::exclusiveOr();
        }
        std::string ExclusiveOrExpressionSyntax::getOperatorSymbol()
        {
            return "^";
        }
    }
}
