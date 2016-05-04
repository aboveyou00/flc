#include "stdafx.h"
#include "BrfalseInstr.h"

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

        void BrfalseInstr::stringify(std::stringstream *stream)
        {
            *stream << "brfalse ";
            getBranchTarget()->stringify(stream);
        }
    }
}
