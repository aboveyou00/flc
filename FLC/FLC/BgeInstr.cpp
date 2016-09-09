#include "stdafx.h"
#include "BgeInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BgeInstr::BgeInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BgeInstr::~BgeInstr()
        {
        }

        bool BgeInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string BgeInstr::base_opcode()
        {
            if (signedArithmetic) return "bge"s;
            else return "bge.un"s;
        }
    }
}
