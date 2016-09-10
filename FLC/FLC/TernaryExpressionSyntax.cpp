#include "stdafx.h"
#include "TernaryExpressionSyntax.h"
#include "ImplicitCastOperator.h"
#include "MethodOverload.h"
#include "BrfalseInstr.h"
#include "BrInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace syntax
    {
        TernaryExpressionSyntax::TernaryExpressionSyntax(ExpressionSyntax* condition, ExpressionSyntax* iftrue, ExpressionSyntax* iffalse)
            : _cond(condition), _iftrue(iftrue), _iffalse(iffalse)
        {
        }
        TernaryExpressionSyntax::~TernaryExpressionSyntax()
        {
            if (_cond != nullptr) delete _cond;
            _cond = nullptr;

            if (_iftrue != nullptr) delete _iftrue;
            _iftrue = nullptr;

            if (_iffalse != nullptr) delete _iffalse;
            _iffalse = nullptr;
        }

        ExpressionSyntax* TernaryExpressionSyntax::getCondition()
        {
            return _cond;
        }
        ExpressionSyntax* TernaryExpressionSyntax::getTrueExpression()
        {
            return _iftrue;
        }
        ExpressionSyntax* TernaryExpressionSyntax::getFalseExpression()
        {
            return _iffalse;
        }

        int TernaryExpressionSyntax::getPrecedence()
        {
            return 1200;
        }

        void TernaryExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _cond->suggestExpressionType(types::RuntimeType::bool8());
            _cond->resolveTypes(ctx);
            if (_cond->getExpressionType() == nullptr)
            {
                _cond->reportError("Cannot resolve expression type for ternary condition.");
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
                _iftrue->suggestExpressionType(suggestedType);
                _iffalse->suggestExpressionType(suggestedType);
            }
            _iftrue->resolveTypes(ctx);
            _iffalse->resolveTypes(ctx);

            if (_iftrue->getExpressionType() != nullptr && _iffalse->getExpressionType() == nullptr)
            {
                _iffalse->suggestExpressionType(_iftrue->getExpressionType());
                _iffalse->resolveTypes(ctx);
            }
            else if (_iftrue->getExpressionType() == nullptr && _iffalse->getExpressionType() != nullptr)
            {
                _iftrue->suggestExpressionType(_iffalse->getExpressionType());
                _iftrue->resolveTypes(ctx);
            }

            if (_iftrue->getExpressionType() != nullptr && _iffalse->getExpressionType() != nullptr)
            {
                if (_iftrue->getExpressionType()->isSameAs(_iffalse->getExpressionType()))
                {
                    _exprType = _iftrue->getExpressionType();
                    return;
                }

                _castTrue = op::Operator::implicitCast()->findOverload(_iftrue->getExpressionType(), _iffalse->getExpressionType());
                _castFalse = op::Operator::implicitCast()->findOverload(_iffalse->getExpressionType(), _iftrue->getExpressionType());
                if (_castTrue != nullptr && _castFalse == nullptr)
                {
                    _exprType = _iffalse->getExpressionType();
                    return;
                }
                else if (_castTrue == nullptr && _castFalse != nullptr)
                {
                    _exprType = _iftrue->getExpressionType();
                    return;
                }

                _castTrue = nullptr;
                _castFalse = nullptr;
            }

            this->reportError("Cannot resolve expression type for ternary expression.");
        }
        types::RuntimeType* TernaryExpressionSyntax::getExpressionType()
        {
            return _exprType;
        }

        void TernaryExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _cond->emit(ctx, method);
            if (_castCondition != nullptr) _castCondition->emitCall(method);

            auto brfalse = new emit::BrfalseInstr();
            method->emit(brfalse);

            _iftrue->emit(ctx, method);
            if (_castTrue != nullptr) _castTrue->emitCall(method);
            auto brafter = new emit::BrInstr();
            method->emit(brafter);

            auto brfalse_target = brfalse->getBranchTarget();
            method->emitDecorator(brfalse_target);
            _iffalse->emit(ctx, method);
            if (_castFalse != nullptr) _castFalse->emitCall(method);

            auto brafter_target = brafter->getBranchTarget();
            method->emitDecorator(brafter_target);
        }

        void TernaryExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _cond->stringify(stream, tabulation);
            *stream << " ? ";
            _iftrue->stringify(stream, 0);
            *stream << " : ";
            _iffalse->stringify(stream, 0);
        }
    }
}
