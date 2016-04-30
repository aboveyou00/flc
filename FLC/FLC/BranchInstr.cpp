#include "stdafx.h"
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        BranchInstr::BranchInstr(BranchTarget *target)
            : _target(target)
        {
        }
        BranchInstr::~BranchInstr()
        {
        }

        BranchTarget *BranchInstr::getBranchTarget()
        {
            return _target;
        }
    }
}
