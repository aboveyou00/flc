#include "stdafx.h"
#include "UnaryExpressionSyntax.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace syntax
    {
        UnaryExpressionSyntax::UnaryExpressionSyntax(string op, ExpressionSyntax* expr)
            : _expr(expr)
        {
            if (op == "+") _op = UnaryOperator::Plus;
            else if (op == "-") _op = UnaryOperator::Minus;
            else if (op == "!") _op = UnaryOperator::Not;
            else if (op == "~") _op = UnaryOperator::Complement;
            else if (op == "++") _op = UnaryOperator::PreIncrement;
            else if (op == "--") _op = UnaryOperator::PreDecrement;
            else
            {
                reportError("Invalid Unary Operator in UnaryExpressionSyntax::ctor: " + op);
                _op = UnaryOperator::ErrorState;
            }
        }
        UnaryExpressionSyntax::~UnaryExpressionSyntax()
        {
        }

        UnaryOperator UnaryExpressionSyntax::getOperator()
        {
            return _op;
        }

        void UnaryExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _expr->resolveTypes(ctx);

            op::UnaryOperator *un_op;
            switch (_op)
            {
            case UnaryOperator::Plus:
                un_op = op::Operator::unaryPlus();
                break;
            case UnaryOperator::Minus:
                un_op = op::Operator::negation();
                break;
            case UnaryOperator::Not:
                un_op = op::Operator::logicalNot();
                break;
            case UnaryOperator::Complement:
                un_op = op::Operator::onesComplement();
                break;
            case UnaryOperator::PreIncrement:
                un_op = op::Operator::increment();
                break;
            case UnaryOperator::PreDecrement:
                un_op = op::Operator::decrement();
                break;
            case UnaryOperator::ErrorState:
            default:
                return;
            }
            _overload = un_op->findOverload(_expr->getExpressionType());

            if (_overload != nullptr)
            {
                _expr->suggestExpressionType(_overload->getParameterInfo(0)->getType());
                _expr->resolveTypes(ctx);
            }
        }
        types::RuntimeType* UnaryExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void UnaryExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            switch (_op)
            {
            case UnaryOperator::Plus:
                *stream << "+";
                break;
            case UnaryOperator::Minus:
                *stream << "-";
                break;
            case UnaryOperator::Not:
                *stream << "!";
                break;
            case UnaryOperator::Complement:
                *stream << "~";
                break;
            case UnaryOperator::PreIncrement:
                *stream << "++";
                break;
            case UnaryOperator::PreDecrement:
                *stream << "--";
                break;
            case UnaryOperator::ErrorState:
            default:
                *stream << "%%ERROR%% ";
                break;
            }
            _expr->stringify(stream, 0);
        }
    }
}
