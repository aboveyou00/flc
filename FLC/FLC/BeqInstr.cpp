#include "stdafx.h"
#include "BeqInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BeqInstr::BeqInstr(BranchTarget *target)
            : BranchInstr(target)
        {
        }
        BeqInstr::~BeqInstr()
        {
        }

        std::string BeqInstr::base_opcode()
        {
            return "beq"s;
        }
    }
}
