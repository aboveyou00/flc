#include "stdafx.h"
#include "EqualityExpressionSyntax.h"
#include "BinaryOperator.h"

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

        types::RuntimeType* EqualityExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr)
            {
                op::BinaryOperator *bin_op;
                switch (_op)
                {
                case EqualityOperator::Equals:
                    bin_op = op::Operator::equality();
                    break;
                case EqualityOperator::NotEquals:
                    bin_op = op::Operator::inequality();
                    break;
                case EqualityOperator::ErrorState:
                default:
                    return nullptr;
                }
                _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());
            }
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void EqualityExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case EqualityOperator::Equals:
                *stream << " == ";
                break;
            case EqualityOperator::NotEquals:
                *stream << " != ";
                break;
            case EqualityOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
