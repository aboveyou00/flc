#include "stdafx.h"
#include "FloatLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        FloatLiteralSyntax::FloatLiteralSyntax(float value)
        {
            val = value;
        }
        FloatLiteralSyntax::~FloatLiteralSyntax()
        {
        }

        float FloatLiteralSyntax::getValue()
        {
            return val;
        }

        string FloatLiteralSyntax::toString()
        {
            stringstream stream;
            stream << val;
            return stream.str();
        }
    }
}
