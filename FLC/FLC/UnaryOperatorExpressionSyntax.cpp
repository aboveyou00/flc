#include "stdafx.h"
#include "UnaryOperatorExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        UnaryOperatorExpressionSyntax::UnaryOperatorExpressionSyntax(ExpressionSyntax* expr)
            : _expr(expr)
        {
        }
        UnaryOperatorExpressionSyntax::~UnaryOperatorExpressionSyntax()
        {
            if (_expr != nullptr) delete _expr;
            _expr = nullptr;
        }

        ExpressionSyntax* UnaryOperatorExpressionSyntax::getOperand()
        {
            return _expr;
        }

        void UnaryOperatorExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _expr->resolveTypes(ctx);

            auto un_op = getUnaryOperator();
            if (un_op == nullptr) return;
            _overload = un_op->findOverload(_expr->getExpressionType());

            if (_overload != nullptr)
            {
                _expr->suggestExpressionType(_overload->getParameterInfo(0)->getType());
                _expr->resolveTypes(ctx);
            }
        }
        types::RuntimeType* UnaryOperatorExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }

        void UnaryOperatorExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _expr->emit(ctx, method);
            //TODO: implicitly convert _expr->getExpressionType() to _overload->getParameterInfo(0)->getType()
            if (_overload != nullptr) _overload->emitCall(method);
        }

        void UnaryOperatorExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getOperatorSymbol();

            if (_expr->getPrecedence() > getPrecedence()) *stream << "(";
            _expr->stringify(stream, 0);
            if (_expr->getPrecedence() > getPrecedence()) *stream << ")";
        }
    }
}
