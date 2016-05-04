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

        void BneInstr::stringify(std::stringstream *stream)
        {
            *stream << "bne ";
            getBranchTarget()->stringify(stream);
        }
    }
}
