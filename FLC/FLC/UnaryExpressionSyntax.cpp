#include "stdafx.h"
#include "UnaryExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        UnaryExpressionSyntax::UnaryExpressionSyntax(string op, ExpressionSyntax* expr)
            : _expr(expr)
        {
            if (op == "+") _op = UnaryOperator::Plus;
            else if (op == "-") _op = UnaryOperator::Minus;
            else if (op == "!") _op = UnaryOperator::Not;
            else
            {
                reportError("Invalid Unary Operator in UnaryExpressionSyntax::ctor: " + op);
                _op = UnaryOperator::ErrorState;
            }
        }
        UnaryExpressionSyntax::~UnaryExpressionSyntax()
        {
        }

        UnaryOperator UnaryExpressionSyntax::getOperator()
        {
            return _op;
        }



        string UnaryExpressionSyntax::toString()
        {
            switch (_op)
            {
            case UnaryOperator::Plus:
                return "+" + _expr->toString();
            case UnaryOperator::Minus:
                return "-" + _expr->toString();
            case UnaryOperator::Not:
                return "!" + _expr->toString();
            case UnaryOperator::ErrorState:
            default:
                return "%%ERROR%% " + _expr->toString();
            }
        }
    }
}
