#include "stdafx.h"
#include "ComplexNameSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        ComplexNameSyntax::ComplexNameSyntax(ExpressionSyntax* baseexpr, string ident)
        {
            lhs = baseexpr;
            name = ident;
        }
        ComplexNameSyntax::~ComplexNameSyntax()
        {
        }

        string ComplexNameSyntax::getName()
        {
            return name;
        }
        ExpressionSyntax* ComplexNameSyntax::getBaseExpression()
        {
            return lhs;
        }

        bool ComplexNameSyntax::isQualifiedName()
        {
            return true;
        }

        string ComplexNameSyntax::toString()
        {
            stringstream stream;
            stream << lhs->toString();
            stream << "::";
            stream << name;
            return stream.str();
        }
    }
}
