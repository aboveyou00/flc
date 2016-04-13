#include "stdafx.h"
#include "RelationalExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        RelationalExpressionSyntax::RelationalExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
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
            _overload = nullptr;
        }
        RelationalExpressionSyntax::~RelationalExpressionSyntax()
        {
        }

        ExpressionSyntax* RelationalExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* RelationalExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        RelationalOperator RelationalExpressionSyntax::getOperator()
        {
            return _op;
        }

        types::RuntimeType* RelationalExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void RelationalExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case RelationalOperator::LessThan:
                *stream << " < ";
                break;
            case RelationalOperator::GreaterThan:
                *stream << " > ";
                break;
            case RelationalOperator::LessThanOrEqualTo:
                *stream << " <= ";
                break;
            case RelationalOperator::GreaterThanOrEqualTo:
                *stream << " >= ";
                break;
            case RelationalOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
