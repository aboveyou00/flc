#include "stdafx.h"
#include "MultiplicativeExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        MultiplicativeExpressionSyntax::MultiplicativeExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "*") _op = MultiplicativeOperator::Multiply;
            else if (op == "/") _op = MultiplicativeOperator::Divide;
            else if (op == "%") _op = MultiplicativeOperator::Remainder;
            else
            {
                reportError("Invalid Multiplicative Operator in MultiplicativeExpressionSyntax::ctor: " + op);
                _op = MultiplicativeOperator::ErrorState;
            }
        }
        MultiplicativeExpressionSyntax::~MultiplicativeExpressionSyntax()
        {
        }

        ExpressionSyntax* MultiplicativeExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* MultiplicativeExpressionSyntax::getRightOperand()
        {
            return _right;
        }
        MultiplicativeOperator MultiplicativeExpressionSyntax::getOperator()
        {
            return _op;
        }



        string MultiplicativeExpressionSyntax::toString()
        {
            switch (_op)
            {
            case MultiplicativeOperator::Multiply:
                return _left->toString() + " * " + _right->toString();
            case MultiplicativeOperator::Divide:
                return _left->toString() + " / " + _right->toString();
            case MultiplicativeOperator::Remainder:
                return _left->toString() + " % " + _right->toString();
            case MultiplicativeOperator::ErrorState:
            default:
                return _left->toString() + "%%ERROR%% " + _right->toString();
            }
        }
    }
}
