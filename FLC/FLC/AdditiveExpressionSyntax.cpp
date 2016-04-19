#include "stdafx.h"
#include "AdditiveExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        AdditiveExpressionSyntax::AdditiveExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
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
        }

        int AdditiveExpressionSyntax::getPrecedence()
        {
            return 300;
        }

        op::BinaryOperator *AdditiveExpressionSyntax::getBinaryOperator()
        {
            switch (_op)
            {
            case AdditiveOperator::Add:
                return op::Operator::addition();

            case AdditiveOperator::Subtract:
                return op::Operator::subtraction();

            case AdditiveOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string AdditiveExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case AdditiveOperator::Add:
                return "+";

            case AdditiveOperator::Subtract:
                return "-";

            case AdditiveOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        AdditiveOperator AdditiveExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
