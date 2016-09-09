#include "stdafx.h"
#include "BrInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BrInstr::BrInstr(BranchTarget *target)
            : BranchInstr(target)
        {
        }
        BrInstr::~BrInstr()
        {
        }

        bool BrInstr::isConditional()
        {
            return false;
        }

        std::string BrInstr::base_opcode()
        {
            return "br"s;
        }
    }
}
