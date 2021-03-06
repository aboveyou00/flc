#include "stdafx.h"
#include "UnaryOperatorExpressionSyntax.h"
#include "CastOperator.h"
#include "MethodOverload.h"
#include "ParameterInfo.h"

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

        int UnaryOperatorExpressionSyntax::getPrecedence()
        {
            return 100;
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

            if (_overload == nullptr)
            {
                this->reportError("Cannot find unary operator overload for operator %s", getOperatorSymbol().c_str());
                return;
            }

            _expr->suggestExpressionType(_overload->getParameterInfo(0)->getType());
            _expr->resolveTypes(ctx);

            if (!_expr->getExpressionType()->isSameAs(_overload->getParameterInfo(0)->getType()))
            {
                _castExpr = op::Operator::implicitCast()->findOverload(_expr->getExpressionType(), _overload->getParameterInfo(0)->getType());
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
            if (_castExpr != nullptr) _castExpr->emitCall(method);
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
