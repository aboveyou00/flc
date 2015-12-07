#include "stdafx.h"
#include "ConditionalOrExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ConditionalOrExpressionSyntax::ConditionalOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ConditionalOrExpressionSyntax::~ConditionalOrExpressionSyntax()
        {
        }

        ExpressionSyntax* ConditionalOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        string ConditionalOrExpressionSyntax::toString()
        {
            return _left->toString() + " || " + _right->toString();
        }
    }
}
