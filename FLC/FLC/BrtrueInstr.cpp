#include "stdafx.h"
#include "BrtrueInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BrtrueInstr::BrtrueInstr(BranchTarget *target)
            : BranchInstr(target)
        {
        }
        BrtrueInstr::~BrtrueInstr()
        {
        }

        std::string BrtrueInstr::base_opcode()
        {
            return "brtrue"s; 
        }
    }
}
