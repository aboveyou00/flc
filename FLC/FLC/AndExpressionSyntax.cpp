#include "stdafx.h"
#include "AndExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        AndExpressionSyntax::AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        AndExpressionSyntax::~AndExpressionSyntax()
        {
        }

        ExpressionSyntax* AndExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* AndExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        string AndExpressionSyntax::toString()
        {
            return _left->toString() + " & " + _right->toString();
        }
    }
}
