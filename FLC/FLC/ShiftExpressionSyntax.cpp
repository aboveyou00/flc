#include "stdafx.h"
#include "ShiftExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        ShiftExpressionSyntax::ShiftExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
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

        int ShiftExpressionSyntax::getPrecedence()
        {
            return 400;
        }

        op::BinaryOperator *ShiftExpressionSyntax::getBinaryOperator()
        {
            switch (_op)
            {
            case ShiftOperator::Left:
                return op::Operator::leftShift();

            case ShiftOperator::Right:
                return op::Operator::rightShift();

            case ShiftOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string ShiftExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case ShiftOperator::Left:
                return "<<";

            case ShiftOperator::Right:
                return ">>";

            case ShiftOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        ShiftOperator ShiftExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
