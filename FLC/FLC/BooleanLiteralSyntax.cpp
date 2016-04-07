#include "stdafx.h"
#include "BooleanLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        BooleanLiteralSyntax::BooleanLiteralSyntax(bool value)
        {
            val = value;
        }
        BooleanLiteralSyntax::~BooleanLiteralSyntax()
        {
        }

        bool BooleanLiteralSyntax::getValue()
        {
            return val;
        }

        string BooleanLiteralSyntax::toString()
        {
            return val ? "true" : "false";
        }
    }
}
