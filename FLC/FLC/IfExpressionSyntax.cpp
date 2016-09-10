#include "stdafx.h"
#include "IfExpressionSyntax.h"
#include "ImplicitCastOperator.h"
#include "MethodOverload.h"
#include "BrfalseInstr.h"
#include "BrInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace syntax
    {
        IfExpressionSyntax::IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr)
            : IfExpressionSyntax(cond, expr, nullptr)
        {
        }
        IfExpressionSyntax::IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, ExpressionSyntax* elseExpr)
            : _cond(cond), _expr(expr), _elseExpr(elseExpr)
        {
        }
        IfExpressionSyntax::~IfExpressionSyntax()
        {
            if (_cond != nullptr) delete _cond;
            _cond = nullptr;

            if (_expr != nullptr) delete _expr;
            _expr = nullptr;

            if (_elseExpr != nullptr) delete _elseExpr;
            _elseExpr = nullptr;
        }

        ExpressionSyntax* IfExpressionSyntax::getCondition()
        {
            return _cond;
        }
        ExpressionSyntax* IfExpressionSyntax::getExpression()
        {
            return _expr;
        }
        ExpressionSyntax* IfExpressionSyntax::getElseExpression()
        {
            return _elseExpr;
        }

        int IfExpressionSyntax::getPrecedence()
        {
            return 2000;
        }

        void IfExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _cond->suggestExpressionType(types::RuntimeType::bool8());
            _cond->resolveTypes(ctx);
            if (_cond->getExpressionType() == nullptr)
            {
                _cond->reportError("Cannot resolve expression type for if statement condition.");
                return;
            }
            if (!_cond->getExpressionType()->isSameAs(types::RuntimeType::bool8()))
            {
                _castCondition = op::Operator::implicitCast()->findOverload(_cond->getExpressionType(), types::RuntimeType::bool8());
                if (_castCondition == nullptr)
                {
                    _cond->reportError("The condition in a ternary expression must be implicitly convertable to boolean.");
                    return;
                }
            }

            if (suggestedType != nullptr)
            {
                _expr->suggestExpressionType(suggestedType);
                if (_elseExpr != nullptr) _elseExpr->suggestExpressionType(suggestedType);
            }
            _expr->resolveTypes(ctx);
            if (_elseExpr != nullptr) _elseExpr->resolveTypes(ctx);

            if (_expr->getExpressionType() != nullptr && _elseExpr != nullptr && _elseExpr->getExpressionType() == nullptr)
            {
                _elseExpr->suggestExpressionType(_expr->getExpressionType());
                _elseExpr->resolveTypes(ctx);
            }
            else if (_expr->getExpressionType() == nullptr && _elseExpr != nullptr && _elseExpr->getExpressionType() != nullptr)
            {
                _expr->suggestExpressionType(_elseExpr->getExpressionType());
                _expr->resolveTypes(ctx);
            }

            if (_expr->getExpressionType() == nullptr || (_elseExpr != nullptr && _elseExpr->getExpressionType() == nullptr)) return;

            if (_elseExpr == nullptr || _expr->getExpressionType()->isSameAs(_elseExpr->getExpressionType()))
            {
                _exprType = _expr->getExpressionType();
                return;
            }

            _castTrue = op::Operator::implicitCast()->findOverload(_expr->getExpressionType(), _elseExpr->getExpressionType());
            _castFalse = op::Operator::implicitCast()->findOverload(_elseExpr->getExpressionType(), _expr->getExpressionType());
            if (_castTrue != nullptr && _castFalse == nullptr)
            {
                _exprType = _elseExpr->getExpressionType();
                return;
            }
            else if (_castTrue == nullptr && _castFalse != nullptr)
            {
                _exprType = _expr->getExpressionType();
                return;
            }

            _castTrue = nullptr;
            _castFalse = nullptr;
        }
        types::RuntimeType* IfExpressionSyntax::getExpressionType()
        {
            return _exprType;
        }

        void IfExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _cond->emit(ctx, method);
            if (_castCondition != nullptr) _castCondition->emitCall(method);

            auto brfalse = new emit::BrfalseInstr();
            method->emit(brfalse);

            _expr->emit(ctx, method);
            if (_castTrue != nullptr) _castTrue->emitCall(method);
            emit::BrInstr *brafter;
            if (_elseExpr != nullptr)
            {
                brafter = new emit::BrInstr();
                method->emit(brafter);
            }

            auto brfalse_target = brfalse->getBranchTarget();
            method->emitDecorator(brfalse_target);
            if (_elseExpr != nullptr)
            {
                _elseExpr->emit(ctx, method);
                if (_castFalse != nullptr) _castFalse->emitCall(method);

                auto brafter_target = brafter->getBranchTarget();
                method->emitDecorator(brafter_target);
            }
        }

        void IfExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "if (";
            _cond->stringify(stream, 0);
            *stream << ") ";
            _expr->stringify(stream, 0);

            if (_elseExpr != nullptr)
            {
                //TODO: Fix stringify for else expression
                *stream << "\r\n";
                tabulate(stream, tabulation);
                *stream << "else ";
                _elseExpr->stringify(stream, 0);
            }
        }
    }
}
