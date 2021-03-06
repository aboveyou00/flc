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

        int SimpleNameSyntax::getPrecedence()
        {
            return 0;
        }

        bool SimpleNameSyntax::isQualifiedName()
        {
            return true;
        }

        void SimpleNameSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* SimpleNameSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }

        void SimpleNameSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: Implement
        }

        void SimpleNameSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            if (qualified) *stream << ":::";
            *stream << name;
        }
    }
}
