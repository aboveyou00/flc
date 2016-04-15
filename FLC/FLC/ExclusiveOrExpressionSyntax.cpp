#include "stdafx.h"
#include "ExclusiveOrExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        ExclusiveOrExpressionSyntax::ExclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ExclusiveOrExpressionSyntax::~ExclusiveOrExpressionSyntax()
        {
        }

        ExpressionSyntax* ExclusiveOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ExclusiveOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        types::RuntimeType* ExclusiveOrExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr)
            {
                op::BinaryOperator *bin_op = op::Operator::exclusiveOr();
                _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());
            }
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void ExclusiveOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " ^ ";
            _right->stringify(stream, 0);
        }
    }
}
