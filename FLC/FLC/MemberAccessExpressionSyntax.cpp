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

        string MemberAccessExpressionSyntax::toString()
        {
            stringstream stream;
            stream << lhs->toString();
            stream << ".";
            stream << ident;
            return stream.str();
        }
    }
}
