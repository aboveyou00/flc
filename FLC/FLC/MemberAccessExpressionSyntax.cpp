#include "stdafx.h"
#include "MemberAccessExpressionSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        MemberAccessExpressionSyntax::MemberAccessExpressionSyntax(ExpressionSyntax* term, string identifier)
        {
            lhs = term;
            ident = identifier;
        }
        MemberAccessExpressionSyntax::~MemberAccessExpressionSyntax()
        {
        }

        bool MemberAccessExpressionSyntax::isQualifiedName()
        {
            return lhs->isQualifiedName();
        }

        types::RuntimeType* MemberAccessExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void MemberAccessExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            lhs->stringify(stream, tabulation);
            *stream << ".";
            *stream << ident;
        }
    }
}
