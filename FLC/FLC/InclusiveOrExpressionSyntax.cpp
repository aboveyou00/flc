#include "stdafx.h"
#include "InclusiveOrExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        InclusiveOrExpressionSyntax::InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
        }
        InclusiveOrExpressionSyntax::~InclusiveOrExpressionSyntax()
        {
        }

        int InclusiveOrExpressionSyntax::getPrecedence()
        {
            return 900;
        }

        op::BinaryOperator *InclusiveOrExpressionSyntax::getBinaryOperator()
        {
            return op::Operator::bitwiseOr();
        }
        std::string InclusiveOrExpressionSyntax::getOperatorSymbol()
        {
            return "|";
        }
    }
}
