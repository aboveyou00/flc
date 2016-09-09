#include "stdafx.h"
#include "OrInstr.h"

namespace flc
{
    namespace emit
    {
        OrInstr::OrInstr()
        {
        }
        OrInstr::~OrInstr()
        {
        }

        std::string OrInstr::opcode()
        {
            return "or"s;
        }
    }
}
