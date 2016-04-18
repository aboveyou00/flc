#include "stdafx.h"
#include "AdditiveExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        AdditiveExpressionSyntax::AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "+") _op = AdditiveOperator::Add;
            else if (op == "-") _op = AdditiveOperator::Subtract;
            else
            {
                reportError("Invalid Additive Operator in AdditiveExpressionSyntax::ctor: " + op);
                _op = AdditiveOperator::ErrorState;
            }
        }
        AdditiveExpressionSyntax::~AdditiveExpressionSyntax()
        {
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
        }

        ExpressionSyntax* AdditiveExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* AdditiveExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        AdditiveOperator AdditiveExpressionSyntax::getOperator()
        {
            return _op;
        }

        void AdditiveExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);

            op::BinaryOperator *bin_op;
            switch (_op)
            {
            case AdditiveOperator::Add:
                bin_op = op::Operator::addition();
                break;
            case AdditiveOperator::Subtract:
                bin_op = op::Operator::subtraction();
                break;
            case AdditiveOperator::ErrorState:
            default:
                return;
            }
            _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());

            _left->suggestExpressionType(_overload->getParameterInfo(0)->getType());
            _right->suggestExpressionType(_overload->getParameterInfo(1)->getType());
            _left->resolveTypes(ctx);
            _right->resolveTypes(ctx);
        }
        types::RuntimeType* AdditiveExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void AdditiveExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case AdditiveOperator::Add:
                *stream << " + ";
                break;
            case AdditiveOperator::Subtract:
                *stream << " - ";
                break;
            case AdditiveOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
