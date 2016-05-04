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

        void BrtrueInstr::stringify(std::stringstream *stream)
        {
            *stream << "brtrue ";
            getBranchTarget()->stringify(stream);
        }
    }
}
