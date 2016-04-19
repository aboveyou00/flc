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
            if (_left != nullptr) delete _left;
            _left = nullptr;

            if (_right != nullptr) delete _right;
            _right = nullptr;
        }

        ExpressionSyntax* ConditionalOrExpressionSyntax::getLeftOperand()
        {
            return _left;
        }
        ExpressionSyntax* ConditionalOrExpressionSyntax::getRightOperand()
        {
            return _right;
        }

        int ConditionalOrExpressionSyntax::getPrecedence()
        {
            return 1100;
        }

        void ConditionalOrExpressionSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* ConditionalOrExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }

        void ConditionalOrExpressionSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: Implement
        }

        void ConditionalOrExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _left->stringify(stream, tabulation);
            *stream << " || ";
            _right->stringify(stream, 0);
        }
    }
}
