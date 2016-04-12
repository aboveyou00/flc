#include "stdafx.h"
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        ExpressionSyntax::ExpressionSyntax()
        {
        }
        ExpressionSyntax::~ExpressionSyntax()
        {
        }

        bool ExpressionSyntax::isQualifiedName()
        {
            return false;
        }
        bool ExpressionSyntax::isLeftHandSide()
        {
            return false;
        }

        void ExpressionSyntax::suggestExpressionType(types::RuntimeType* type)
        {
            suggestedType = type;
        }
    }
}
