#include "stdafx.h"
#include "EqualityExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        EqualityExpressionSyntax::EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "==") _op = EqualityOperator::Equals;
            else if (op == "!=") _op = EqualityOperator::NotEquals;
            else
            {
                reportError("Invalid EqualityOperator Operator in EqualityExpressionSyntax::ctor: " + op);
                _op = EqualityOperator::ErrorState;
            }
        }
        EqualityExpressionSyntax::~EqualityExpressionSyntax()
        {
        }

        ExpressionSyntax* EqualityExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* EqualityExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        EqualityOperator EqualityExpressionSyntax::getOperator()
        {
            return _op;
        }



        string EqualityExpressionSyntax::toString()
        {
            switch (_op)
            {
            case EqualityOperator::Equals:
                return _left->toString() + " == " + _right->toString();
            case EqualityOperator::NotEquals:
                return _left->toString() + " != " + _right->toString();
            case EqualityOperator::ErrorState:
            default:
                return _left->toString() + "%%ERROR%% " + _right->toString();
            }
        }
    }
}
