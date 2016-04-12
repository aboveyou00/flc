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

        types::RuntimeType* ComplexNameSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void ComplexNameSyntax::stringify(stringstream* stream, int tabulation)
        {
            lhs->stringify(stream, tabulation);
            *stream << "::";
            *stream << name;
        }
    }
}
