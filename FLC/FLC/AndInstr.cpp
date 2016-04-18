#include "stdafx.h"
#include "AndInstr.h"

namespace flc
{
    namespace emit
    {
        AndInstr::AndInstr()
        {
        }
        AndInstr::~AndInstr()
        {
        }

        void AndInstr::stringify(std::stringstream *stream)
        {
            *stream << "and";
        }
    }
}
