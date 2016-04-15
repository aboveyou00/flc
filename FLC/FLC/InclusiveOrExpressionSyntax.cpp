#include "stdafx.h"
#include "InclusiveOrExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        InclusiveOrExpressionSyntax::InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        InclusiveOrExpressionSyntax::~InclusiveOrExpressionSyntax()
        {
        }

        ExpressionSyntax* InclusiveOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* InclusiveOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        types::RuntimeType* InclusiveOrExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr)
            {
                op::BinaryOperator *bin_op = op::Operator::bitwiseOr();
                _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());
            }
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void InclusiveOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " | ";
            _right->stringify(stream, 0);
        }
    }
}
