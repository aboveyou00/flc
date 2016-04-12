#include "stdafx.h"
#include "AndExpressionSyntax.h"

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
            //TODO: Implement
            return nullptr;
        }



        void AndExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " & ";
            _right->stringify(stream, 0);
        }
    }
}
