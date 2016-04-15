#include "stdafx.h"
#include "AndExpressionSyntax.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace syntax
    {
        AndExpressionSyntax::AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        AndExpressionSyntax::~AndExpressionSyntax()
        {
        }

        ExpressionSyntax* AndExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* AndExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        types::RuntimeType* AndExpressionSyntax::getExpressionType()
        {
            if (_overload == nullptr)
            {
                op::BinaryOperator *bin_op = op::Operator::bitwiseAnd();
                _overload = bin_op->findOverload(_left->getExpressionType(), _right->getExpressionType());
            }
            if (_overload == nullptr) return nullptr;
            return _overload->getReturnType();
        }



        void AndExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " & ";
            _right->stringify(stream, 0);
        }
    }
}
