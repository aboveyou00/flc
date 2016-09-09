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

        std::string BreakInstr::opcode()
        {
            return "break"s;
        }
    }
}
