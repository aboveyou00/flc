#include "stdafx.h"
#include "BneInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BneInstr::BneInstr(BranchTarget *target)
            : BranchInstr(target)
        {
        }
        BneInstr::~BneInstr()
        {
        }

        std::string BneInstr::base_opcode()
        {
            return "bne";
        }
    }
}
