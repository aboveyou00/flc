#include "stdafx.h"
#include "ShiftExpressionSyntax.h"
#include "BinaryOperator.h"

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
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
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

        void ShiftExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            op::BinaryOperator *bin_op;
            switch (_op)
            {
            case ShiftOperator::Left:
                bin_op = op::Operator::leftShift();
                break;
            case ShiftOperator::Right:
                bin_op = op::Operator::rightShift();
                break;
            case ShiftOperator::ErrorState:
            default:
                return;
            }
            _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());

            if (_overload != nullptr)
            {
                _left->suggestExpressionType(_overload->getParameterInfo(0)->getType());
                _right->suggestExpressionType(_overload->getParameterInfo(1)->getType());
                _left->resolveTypes(ctx);
                _right->resolveTypes(ctx);
            }
        }
        types::RuntimeType* ShiftExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }

        void ShiftExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _left->emit(ctx, method);
            //TODO: implicitly convert _left->getExpressionType() to _overload->getParameterInfo(0)->getType()
            _right->emit(ctx, method);
            //TODO: implicitly convert _right->getExpressionType() to _overload->getParameterInfo(1)->getType()
            //TODO: emit operator instructions
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
