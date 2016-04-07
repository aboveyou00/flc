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

        string SimpleNameSyntax::toString()
        {
            stringstream stream;
            if (qualified) stream << ":::";
            stream << name;
            return stream.str();
        }
    }
}
