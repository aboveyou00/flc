#include "stdafx.h"
#include "ConditionalOrExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ConditionalOrExpressionSyntax::ConditionalOrExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ConditionalOrExpressionSyntax::~ConditionalOrExpressionSyntax()
        {
        }

        ExpressionSyntax* ConditionalOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        types::RuntimeType* ConditionalOrExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void ConditionalOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " || ";
            _right->stringify(stream, 0);
        }
    }
}
