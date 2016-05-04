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

        void BeqInstr::stringify(std::stringstream *stream)
        {
            *stream << "beq ";
            getBranchTarget()->stringify(stream);
        }
    }
}
