#include "stdafx.h"
#include "EqualityExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        EqualityExpressionSyntax::EqualityExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
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

        ExpressionSyntax* EqualityExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* EqualityExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        EqualityOperator EqualityExpressionSyntax::getOperator()
        {
            return _op;
        }



        void EqualityExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case EqualityOperator::Equals:
                *stream << " == ";
                break;
            case EqualityOperator::NotEquals:
                *stream << " != ";
                break;
            case EqualityOperator::ErrorState:
            default:
                *stream << " %%ERROR%% ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
