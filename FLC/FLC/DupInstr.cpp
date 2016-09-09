#include "stdafx.h"
#include "DupInstr.h"

namespace flc
{
    namespace emit
    {
        DupInstr::DupInstr()
        {
        }
        DupInstr::~DupInstr()
        {
        }

        std::string DupInstr::opcode()
        {
            return "dup"s;
        }
    }
}
