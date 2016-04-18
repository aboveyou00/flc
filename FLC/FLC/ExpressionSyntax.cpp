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

        void ExpressionSyntax::registerNames(types::NameResolutionContextStack *)
        {
        }
        void ExpressionSyntax::resolveNames(types::NameResolutionContextStack *)
        {
        }
        void ExpressionSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
        }

        void ExpressionSyntax::suggestExpressionType(types::RuntimeType* type)
        {
            suggestedType = type;
        }
    }
}
