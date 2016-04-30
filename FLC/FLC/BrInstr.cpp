#include "stdafx.h"
#include "BrInstr.h"

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
        void BrInstr::stringify(std::stringstream *stream)
        {
            *stream << "br ";
            *stream << getBranchTarget()->getName();
        }
    }
}
