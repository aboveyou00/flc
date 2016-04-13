#include "stdafx.h"
#include "MultiplicativeExpressionSyntax.h"
#include "BinaryOperator.h"

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

        types::RuntimeType* MultiplicativeExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr)
            {
                op::BinaryOperator *bin_op;
                switch (_op)
                {
                case MultiplicativeOperator::Multiply:
                    bin_op = op::Operator::addition;
                    break;
                case MultiplicativeOperator::Divide:
                    bin_op = op::Operator::subtraction;
                    break;
                case MultiplicativeOperator::Remainder:
                    bin_op = op::Operator::subtraction;
                    break;
                case MultiplicativeOperator::ErrorState:
                default:
                    return nullptr;
                }
                _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());
            }
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void MultiplicativeExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case MultiplicativeOperator::Multiply:
                *stream << " * ";
                break;
            case MultiplicativeOperator::Divide:
                *stream << " / ";
                break;
            case MultiplicativeOperator::Remainder:
                *stream << " % ";
                break;
            case MultiplicativeOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
