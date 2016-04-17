#include "stdafx.h"
#include "SimpleNameSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        SimpleNameSyntax::SimpleNameSyntax(string ident, bool fullyQualified)
        {
            name = ident;
            qualified = fullyQualified;
        }
        SimpleNameSyntax::~SimpleNameSyntax()
        {
        }

        string SimpleNameSyntax::getName()
        {
            return name;
        }
        bool SimpleNameSyntax::isFullyQualified()
        {
            return qualified;
        }

        bool SimpleNameSyntax::isQualifiedName()
        {
            return true;
        }

        void SimpleNameSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            //TODO: Implement
        }
        types::RuntimeType* SimpleNameSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void SimpleNameSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            if (qualified) *stream << ":::";
            *stream << name;
        }
    }
}
