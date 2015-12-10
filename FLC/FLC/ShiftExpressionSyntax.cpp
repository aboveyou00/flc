#include "stdafx.h"
#include "ShiftExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ShiftExpressionSyntax::ShiftExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "<<") _op = ShiftOperator::Left;
            else if (op == ">>") _op = ShiftOperator::Right;
            else
            {
                reportError("Invalid ShiftOperator Operator in ShiftExpressionSyntax::ctor: " + op);
                _op = ShiftOperator::ErrorState;
            }
        }
        ShiftExpressionSyntax::~ShiftExpressionSyntax()
        {
        }

        ExpressionSyntax* ShiftExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ShiftExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        ShiftOperator ShiftExpressionSyntax::getOperator()
        {
            return _op;
        }



        string ShiftExpressionSyntax::toString()
        {
            switch (_op)
            {
            case ShiftOperator::Left:
                return _left->toString() + " << " + _right->toString();
            case ShiftOperator::Right:
                return _left->toString() + " >> " + _right->toString();
            case ShiftOperator::ErrorState:
            default:
                return _left->toString() + "%%ERROR%% " + _right->toString();
            }
        }
    }
}
