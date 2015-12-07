#include "stdafx.h"
#include "ExclusiveOrExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ExclusiveOrExpressionSyntax::ExclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ExclusiveOrExpressionSyntax::~ExclusiveOrExpressionSyntax()
        {
        }

        ExpressionSyntax* ExclusiveOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ExclusiveOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        string ExclusiveOrExpressionSyntax::toString()
        {
            return _left->toString() + " ^ " + _right->toString();
        }
    }
}
