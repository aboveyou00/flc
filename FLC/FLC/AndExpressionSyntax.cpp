#include "stdafx.h"
#include "AndExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        AndExpressionSyntax::AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
        }
        AndExpressionSyntax::~AndExpressionSyntax()
        {
        }

        op::BinaryOperator *AndExpressionSyntax::getBinaryOperator()
        {
            return op::Operator::bitwiseAnd();
        }
        std::string AndExpressionSyntax::getOperatorSymbol()
        {
            return "&";
        }
    }
}
