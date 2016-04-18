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
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
        }

        ExpressionSyntax* ConditionalAndExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalAndExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        void ConditionalAndExpressionSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* ConditionalAndExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void ConditionalAndExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " && ";
            _right->stringify(stream, 0);
        }
    }
}
