#include "stdafx.h"
#include "StringLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        StringLiteralSyntax::StringLiteralSyntax(string strval)
        {
            str = strval;
        }
        StringLiteralSyntax::~StringLiteralSyntax()
        {
        }
        
        string StringLiteralSyntax::getValue()
        {
            return str;
        }

        string StringLiteralSyntax::toString()
        {
            stringstream stream;
            stream << "\"" << str << "\"";
            return stream.str();
        }
    }
}
