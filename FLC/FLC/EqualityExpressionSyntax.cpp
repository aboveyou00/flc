#include "stdafx.h"
#include "EqualityExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        EqualityExpressionSyntax::EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
            if (op == "==") _op = EqualityOperator::Equals;
            else if (op == "!=") _op = EqualityOperator::NotEquals;
            else
            {
                reportError("Invalid EqualityOperator Operator in EqualityExpressionSyntax::ctor: " + op);
                _op = EqualityOperator::ErrorState;
            }
        }
        EqualityExpressionSyntax::~EqualityExpressionSyntax()
        {
        }

        int EqualityExpressionSyntax::getPrecedence()
        {
            return 600;
        }

        op::BinaryOperator *EqualityExpressionSyntax::getBinaryOperator()
        {
            switch (_op)
            {
            case EqualityOperator::Equals:
                return op::Operator::equality();

            case EqualityOperator::NotEquals:
                return op::Operator::inequality();

            case EqualityOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string EqualityExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case EqualityOperator::Equals:
                return "==";

            case EqualityOperator::NotEquals:
                return "!=";

            case EqualityOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        EqualityOperator EqualityExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
