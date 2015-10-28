#include "stdafx.h"
#include "Syntax.h"

namespace flc
{
    namespace syntax
    {
        Syntax::Syntax()
        {
        }
        Syntax::~Syntax()
        {
        }

        string Syntax::toString()
        {
            reportNotImplemented("Syntax::toString not implemented for a subclass.");
            return "ERROR";
        }


    }
}