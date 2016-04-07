#include "stdafx.h"
#include "IntegerLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        IntegerLiteralSyntax::IntegerLiteralSyntax(int value)
        {
            val = value;
        }
        IntegerLiteralSyntax::~IntegerLiteralSyntax()
        {
        }

        int IntegerLiteralSyntax::getValue()
        {
            return val;
        }

        string IntegerLiteralSyntax::toString()
        {
            stringstream stream;
            stream << val;
            return stream.str();
        }
    }
}
