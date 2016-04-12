#include "stdafx.h"
#include "ExclusiveOrExpressionSyntax.h"

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
            //TODO: Implement
            return nullptr;
        }



        void ExclusiveOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " ^ ";
            _right->stringify(stream, 0);
        }
    }
}
