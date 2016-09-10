#include "stdafx.h"
#include "BinaryOperatorExpressionSyntax.h"
#include "CastOperator.h"
#include "MethodOverload.h"
#include "ParameterInfo.h"

namespace flc
{
    namespace syntax
    {
        BinaryOperatorExpressionSyntax::BinaryOperatorExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        BinaryOperatorExpressionSyntax::~BinaryOperatorExpressionSyntax()
        {
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
        }

        ExpressionSyntax* BinaryOperatorExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* BinaryOperatorExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        void BinaryOperatorExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            auto bin_op = getBinaryOperator();
            if (bin_op == nullptr) return;
            _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());

            if (_overload == nullptr)
            {
                this->reportError("Cannot find binary operator overload for operator %s", getOperatorSymbol());
                return;
            }

            _left->suggestExpressionType(_overload->getParameterInfo(0)->getType());
            _right->suggestExpressionType(_overload->getParameterInfo(1)->getType());
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            if (!_left->getExpressionType()->isSameAs(_overload->getParameterInfo(0)->getType()))
            {
                _castLeft = op::Operator::implicitCast()->findOverload(_left->getExpressionType(), _overload->getParameterInfo(0)->getType());
            }
            if (!_right->getExpressionType()->isSameAs(_overload->getParameterInfo(1)->getType()))
            {
                _castRight = op::Operator::implicitCast()->findOverload(_right->getExpressionType(), _overload->getParameterInfo(1)->getType());
            }
        }
        types::RuntimeType* BinaryOperatorExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }

        void BinaryOperatorExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _left->emit(ctx, method);
            if (_castLeft != nullptr) _castLeft->emitCall(method);

            _right->emit(ctx, method);
            if (_castRight != nullptr) _castRight->emitCall(method);

            if (_overload != nullptr) _overload->emitCall(method);
        }

        void BinaryOperatorExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);

            if (_left->getPrecedence() > getPrecedence()) *stream << "(";
            _left->stringify(stream, 0);
            if (_left->getPrecedence() > getPrecedence()) *stream << ")";

            *stream << " " << getOperatorSymbol() << " ";

            if (_right->getPrecedence() > getPrecedence()) *stream << "(";
            _right->stringify(stream, 0);
            if (_right->getPrecedence() > getPrecedence()) *stream << ")";
        }
    }
}
