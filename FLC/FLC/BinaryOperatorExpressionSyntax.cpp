#include "stdafx.h"
#include "BinaryOperatorExpressionSyntax.h"

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

            if (_overload != nullptr)
            {
                _left->suggestExpressionType(_overload->getParameterInfo(0)->getType());
                _right->suggestExpressionType(_overload->getParameterInfo(1)->getType());
                _left->resolveTypes(ctx);
                _right->resolveTypes(ctx);
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
            //TODO: implicitly convert _left->getExpressionType() to _overload->getParameterInfo(0)->getType()
            _right->emit(ctx, method);
            //TODO: implicitly convert _right->getExpressionType() to _overload->getParameterInfo(1)->getType()
            if (_overload != nullptr) _overload->emitCall(method);
        }

        void BinaryOperatorExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " " << getOperatorSymbol() << " ";
            _right->stringify(stream, 0);
        }
    }
}
