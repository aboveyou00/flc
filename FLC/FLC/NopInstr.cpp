#include "stdafx.h"
#include "NopInstr.h"

namespace flc
{
    namespace emit
    {
        NopInstr::NopInstr()
        {
        }
        NopInstr::~NopInstr()
        {
        }

        std::string NopInstr::opcode()
        {
            return "nop"s;
        }
    }
}
