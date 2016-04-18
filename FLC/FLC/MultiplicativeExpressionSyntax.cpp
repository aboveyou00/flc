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
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
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

        void MultiplicativeExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            op::BinaryOperator *bin_op;
            switch (_op)
            {
            case MultiplicativeOperator::Multiply:
                bin_op = op::Operator::addition();
                break;
            case MultiplicativeOperator::Divide:
                bin_op = op::Operator::subtraction();
                break;
            case MultiplicativeOperator::Remainder:
                bin_op = op::Operator::subtraction();
                break;
            case MultiplicativeOperator::ErrorState:
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
        types::RuntimeType* MultiplicativeExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }

        void MultiplicativeExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _left->emit(ctx, method);
            //TODO: implicitly convert _left->getExpressionType() to _overload->getParameterInfo(0)->getType()
            _right->emit(ctx, method);
            //TODO: implicitly convert _right->getExpressionType() to _overload->getParameterInfo(1)->getType()
            //TODO: emit operator instructions
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
