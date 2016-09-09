#include "stdafx.h"
#include "BrfalseInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BrfalseInstr::BrfalseInstr(BranchTarget *target)
            : BranchInstr(target)
        {
        }
        BrfalseInstr::~BrfalseInstr()
        {
        }

        std::string BrfalseInstr::base_opcode()
        {
            return "brfalse"s; //Or brnull, or brzero
        }
    }
}
