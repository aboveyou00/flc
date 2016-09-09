#include "stdafx.h"
#include "PopInstr.h"

namespace flc
{
    namespace emit
    {
        PopInstr::PopInstr()
        {
        }
        PopInstr::~PopInstr()
        {
        }

        std::string PopInstr::opcode()
        {
            return "pop"s;
        }
    }
}
