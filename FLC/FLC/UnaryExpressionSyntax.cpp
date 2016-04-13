#include "stdafx.h"
#include "UnaryExpressionSyntax.h"

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
            _overload = nullptr;
        }
        UnaryExpressionSyntax::~UnaryExpressionSyntax()
        {
        }

        UnaryOperator UnaryExpressionSyntax::getOperator()
        {
            return _op;
        }

        types::RuntimeType* UnaryExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
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
