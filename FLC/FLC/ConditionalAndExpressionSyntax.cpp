#include "stdafx.h"
#include "ConditionalAndExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ConditionalAndExpressionSyntax::ConditionalAndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ConditionalAndExpressionSyntax::~ConditionalAndExpressionSyntax()
        {
        }

        ExpressionSyntax* ConditionalAndExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalAndExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        string ConditionalAndExpressionSyntax::toString()
        {
            return _left->toString() + " && " + _right->toString();
        }
    }
}
