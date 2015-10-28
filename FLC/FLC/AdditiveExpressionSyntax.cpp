#include "stdafx.h"
#include "AdditiveExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        AdditiveExpressionSyntax::AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "+") _op = AdditiveOperator::Add;
            else if (op == "-") _op = AdditiveOperator::Subtract;
            else
            {
                reportError("Invalid Additive Operator in AdditiveExpressionSyntax::ctor: " + op);
                _op = AdditiveOperator::ErrorState;
            }
        }
        AdditiveExpressionSyntax::~AdditiveExpressionSyntax()
        {
        }

        ExpressionSyntax* AdditiveExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* AdditiveExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        AdditiveOperator AdditiveExpressionSyntax::getOperator()
        {
            return _op;
        }



        string AdditiveExpressionSyntax::toString()
        {
            switch (_op)
            {
            case AdditiveOperator::Add:
                return _left->toString() + "+" + _right->toString();
            case AdditiveOperator::Subtract:
                return _left->toString() + "-" + _right->toString();
            case AdditiveOperator::ErrorState:
            default:
                return _left->toString() + "%%ERROR%% " + _right->toString();
            }
        }
    }
}
