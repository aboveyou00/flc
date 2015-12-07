#include "stdafx.h"
#include "InclusiveOrExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        InclusiveOrExpressionSyntax::InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        InclusiveOrExpressionSyntax::~InclusiveOrExpressionSyntax()
        {
        }

        ExpressionSyntax* InclusiveOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* InclusiveOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        string InclusiveOrExpressionSyntax::toString()
        {
            return _left->toString() + " | " + _right->toString();
        }
    }
}
