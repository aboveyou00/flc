#include "stdafx.h"
#include "BreakInstr.h"

namespace flc
{
    namespace emit
    {
        BreakInstr::BreakInstr()
        {
        }
        BreakInstr::~BreakInstr()
        {
        }

        void BreakInstr::stringify(std::stringstream *stream)
        {
            *stream << "break";
        }
    }
}
