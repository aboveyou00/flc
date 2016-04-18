#include "stdafx.h"
#include "MultiplicativeExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        MultiplicativeExpressionSyntax::MultiplicativeExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
            if (op == "*") _op = MultiplicativeOperator::Multiply;
            else if (op == "/") _op = MultiplicativeOperator::Divide;
            else if (op == "%") _op = MultiplicativeOperator::Remainder;
            else
            {
                reportError("Invalid Multiplicative Operator in MultiplicativeExpressionSyntax::ctor: " + op);
                _op = MultiplicativeOperator::ErrorState;
            }
        }
        MultiplicativeExpressionSyntax::~MultiplicativeExpressionSyntax()
        {
        }

        op::BinaryOperator *MultiplicativeExpressionSyntax::getBinaryOperator()
        {
            switch (_op)
            {
            case MultiplicativeOperator::Multiply:
                return op::Operator::multiplication();

            case MultiplicativeOperator::Divide:
                return op::Operator::division();

            case MultiplicativeOperator::Remainder:
                return op::Operator::modulus();

            case MultiplicativeOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string MultiplicativeExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case MultiplicativeOperator::Multiply:
                return "*";

            case MultiplicativeOperator::Divide:
                return "/";

            case MultiplicativeOperator::Remainder:
                return "%";

            case MultiplicativeOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        MultiplicativeOperator MultiplicativeExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
