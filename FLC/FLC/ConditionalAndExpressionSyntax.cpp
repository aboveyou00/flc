#include "stdafx.h"
#include "ConditionalAndExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ConditionalAndExpressionSyntax::ConditionalAndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : _left(left), _right(right)
        {
        }
        ConditionalAndExpressionSyntax::~ConditionalAndExpressionSyntax()
        {
        }

        ExpressionSyntax* ConditionalAndExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalAndExpressionSyntax::getRightOperand()
        {
            return _right;
        }



        void ConditionalAndExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " && ";
            _right->stringify(stream, 0);
        }
    }
}
