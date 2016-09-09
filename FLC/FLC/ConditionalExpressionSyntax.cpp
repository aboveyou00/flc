#include "stdafx.h"
#include "ConditionalExpressionSyntax.h"
#include "ImplicitCastOperator.h"
#include "MethodOverload.h"
#include "RuntimeType.h"
#include "BranchInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace syntax
    {
        ConditionalExpressionSyntax::ConditionalExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right), _castLeft(nullptr), _castRight(nullptr)
        {
        }
        ConditionalExpressionSyntax::~ConditionalExpressionSyntax()
        {
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
        }

        ExpressionSyntax* ConditionalExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        void ConditionalExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->suggestExpressionType(types::RuntimeType::bool8());
            _right->suggestExpressionType(types::RuntimeType::bool8());
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            if (!_left->getExpressionType()->isSameAs(types::RuntimeType::bool8()))
            {
                _castLeft = op::Operator::implicitCast()->findOverload(_left->getExpressionType(), types::RuntimeType::bool8());
            }
            if (!_right->getExpressionType()->isSameAs(types::RuntimeType::bool8()))
            {
                _castRight = op::Operator::implicitCast()->findOverload(_right->getExpressionType(), types::RuntimeType::bool8());
            }
        }
        types::RuntimeType* ConditionalExpressionSyntax::getExpressionType()
        {
            return types::RuntimeType::bool8();
        }

        void ConditionalExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            _left->emit(ctx, method);
            if (_castLeft != nullptr) _castLeft->emitCall(method);

            auto branch = createBranchInstr();
            method->emit(branch);

            _right->emit(ctx, method);
            if (_castRight != nullptr) _castRight->emitCall(method);
            emit::InstrDecorator *target = branch->getBranchTarget();
            method->emitDecorator(target);
        }

        void ConditionalExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " " << getOperatorSymbol() << " ";
            _right->stringify(stream, 0);
        }
    }
}
