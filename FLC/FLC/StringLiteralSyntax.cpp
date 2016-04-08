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

        void StringLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "\"";
            *stream << str;
            *stream << "\"";
        }
    }
}
