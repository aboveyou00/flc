#include "stdafx.h"
#include "NullLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        NullLiteralSyntax::NullLiteralSyntax()
        {
        }
        NullLiteralSyntax::~NullLiteralSyntax()
        {
        }

        string NullLiteralSyntax::toString()
        {
            return "null";
        }
    }
}
