#include "stdafx.h"
#include "InclusiveOrExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        InclusiveOrExpressionSyntax::InclusiveOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
            _overload = nullptr;
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
            //TODO: Implement
            return nullptr;
        }



        void InclusiveOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " | ";
            _right->stringify(stream, 0);
        }
    }
}
