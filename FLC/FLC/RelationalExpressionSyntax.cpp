#include "stdafx.h"
#include "RelationalExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        RelationalExpressionSyntax::RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "<") _op = RelationalOperator::LessThan;
            else if (op == ">") _op = RelationalOperator::GreaterThan;
            else if (op == "<=") _op = RelationalOperator::LessThanOrEqualTo;
            else if (op == ">=") _op = RelationalOperator::GreaterThanOrEqualTo;
            else
            {
                reportError("Invalid RelationalOperator Operator in RelationalExpressionSyntax::ctor: " + op);
                _op = RelationalOperator::ErrorState;
            }
        }
        RelationalExpressionSyntax::~RelationalExpressionSyntax()
        {
        }

        ExpressionSyntax* RelationalExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* RelationalExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        RelationalOperator RelationalExpressionSyntax::getOperator()
        {
            return _op;
        }



        string RelationalExpressionSyntax::toString()
        {
            switch (_op)
            {
            case RelationalOperator::LessThan:
                return _left->toString() + " < " + _right->toString();
            case RelationalOperator::GreaterThan:
                return _left->toString() + " > " + _right->toString();
            case RelationalOperator::LessThanOrEqualTo:
                return _left->toString() + " <= " + _right->toString();
            case RelationalOperator::GreaterThanOrEqualTo:
                return _left->toString() + " >= " + _right->toString();
            case RelationalOperator::ErrorState:
            default:
                return _left->toString() + "%%ERROR%% " + _right->toString();
            }
        }
    }
}
