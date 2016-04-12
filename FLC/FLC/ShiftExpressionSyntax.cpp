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

        types::RuntimeType* ShiftExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void ShiftExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case ShiftOperator::Left:
                *stream << " << ";
                break;
            case ShiftOperator::Right:
                *stream << " >> ";
                break;
            case ShiftOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
