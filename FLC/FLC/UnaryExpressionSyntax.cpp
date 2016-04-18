#include "stdafx.h"
#include "UnaryExpressionSyntax.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace syntax
    {
        UnaryExpressionSyntax::UnaryExpressionSyntax(string op, ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
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

        op::UnaryOperator *UnaryExpressionSyntax::getUnaryOperator()
        {
            switch (_op)
            {
            case UnaryOperator::Plus:
                return op::Operator::unaryPlus();

            case UnaryOperator::Minus:
                return op::Operator::negation();

            case UnaryOperator::Not:
                return op::Operator::logicalNot();

            case UnaryOperator::Complement:
                return op::Operator::onesComplement();

            case UnaryOperator::PreIncrement:
                return op::Operator::increment();

            case UnaryOperator::PreDecrement:
                return op::Operator::decrement();

            case UnaryOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string UnaryExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case UnaryOperator::Plus:
                return "+";

            case UnaryOperator::Minus:
                return "-";

            case UnaryOperator::Not:
                return  "!";

            case UnaryOperator::Complement:
                return "~";

            case UnaryOperator::PreIncrement:
                return "++";

            case UnaryOperator::PreDecrement:
                return "--";

            case UnaryOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        UnaryOperator UnaryExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
