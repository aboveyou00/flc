#include "stdafx.h"
#include "AssignmentExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        AssignmentExpressionSyntax::AssignmentExpressionSyntax(ExpressionSyntax* left, string op, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            if (op == "=") _op = AssignmentOperator::None;
            else if (op == "+=") _op = AssignmentOperator::Add;
            else if (op == "-=") _op = AssignmentOperator::Subtract;
            else if (op == "*=") _op = AssignmentOperator::Multiply;
            else if (op == "/=") _op = AssignmentOperator::Divide;
            else if (op == "%=") _op = AssignmentOperator::Remainder;
            else if (op == "|=") _op = AssignmentOperator::Or;
            else if (op == "&=") _op = AssignmentOperator::And;
            else if (op == "^=") _op = AssignmentOperator::Not;
            else if (op == "<<=") _op = AssignmentOperator::ShiftLeft;
            else if (op == ">>=") _op = AssignmentOperator::ShiftRight;
            else
            {
                reportError("Invalid AssignmentOperator Operator in AssignmentExpressionSyntax::ctor: " + op);
                _op = AssignmentOperator::ErrorState;
            }
        }
        AssignmentExpressionSyntax::~AssignmentExpressionSyntax()
        {
        }

        ExpressionSyntax* AssignmentExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* AssignmentExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        AssignmentOperator AssignmentExpressionSyntax::getOperator()
        {
            return _op;
        }

        void AssignmentExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _left->resolveTypes(ctx);
            _right->suggestExpressionType(_left->getExpressionType());
            _right->resolveTypes(ctx);
        }
        types::RuntimeType* AssignmentExpressionSyntax::getExpressionType()
        {
            return _left->getExpressionType();
        }



        void AssignmentExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            switch (_op)
            {
            case AssignmentOperator::None:
                *stream << " = ";
                break;
            case AssignmentOperator::Add:
                *stream << " += ";
                break;
            case AssignmentOperator::Subtract:
                *stream << " -= ";
                break;
            case AssignmentOperator::Multiply:
                *stream << " *= ";
                break;
            case AssignmentOperator::Divide:
                *stream << " /= ";
                break;
            case AssignmentOperator::Remainder:
                *stream << " %= ";
                break;
            case AssignmentOperator::Or:
                *stream << " |= ";
                break;
            case AssignmentOperator::And:
                *stream << " &= ";
                break;
            case AssignmentOperator::Not:
                *stream << " ^= ";
                break;
            case AssignmentOperator::ShiftLeft:
                *stream << " <<= ";
                break;
            case AssignmentOperator::ShiftRight:
                *stream << " >>= ";
                break;
            case AssignmentOperator::ErrorState:
            default:
                *stream << " %%ERROR%% = ";
                break;
            }
            _right->stringify(stream, 0);
        }
    }
}
