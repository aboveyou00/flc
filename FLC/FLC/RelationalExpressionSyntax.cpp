#include "stdafx.h"
#include "RelationalExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        RelationalExpressionSyntax::RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : BinaryOperatorExpressionSyntax(left, right)
        {
            if (op == "<") _op = RelationalOperator::LessThan;
            else if (op == ">") _op = RelationalOperator::GreaterThan;
            else if (op == "<=") _op = RelationalOperator::LessThanOrEqualTo;
            else if (op == ">=") _op = RelationalOperator::GreaterThanOrEqualTo;
            else
            {
                reportError("Invalid RelationalOperator Operator in RelationalExpressionSyntax::ctor: " + op);
                _op = RelationalOperator::ErrorState;
            }
        }
        RelationalExpressionSyntax::~RelationalExpressionSyntax()
        {
        }

        op::BinaryOperator *RelationalExpressionSyntax::getBinaryOperator()
        {
            switch (_op)
            {
            case RelationalOperator::LessThan:
                return op::Operator::lessThan();

            case RelationalOperator::LessThanOrEqualTo:
                return op::Operator::lessThanOrEqual();

            case RelationalOperator::GreaterThan:
                return op::Operator::greaterThan();

            case RelationalOperator::GreaterThanOrEqualTo:
                return op::Operator::greaterThanOrEqual();

            case RelationalOperator::ErrorState:
            default:
                return nullptr;
            }
        }
        std::string RelationalExpressionSyntax::getOperatorSymbol()
        {
            switch (_op)
            {
            case RelationalOperator::LessThan:
                return "<";

            case RelationalOperator::GreaterThan:
                return ">";

            case RelationalOperator::LessThanOrEqualTo:
                return "<=";

            case RelationalOperator::GreaterThanOrEqualTo:
                return ">=";

            case RelationalOperator::ErrorState:
            default:
                return "%%ERROR%%";
            }
        }

        RelationalOperator RelationalExpressionSyntax::getOperator()
        {
            return _op;
        }
    }
}
