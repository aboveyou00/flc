#include "stdafx.h"
#include "BltInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BltInstr::BltInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BltInstr::~BltInstr()
        {
        }

        bool BltInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string BltInstr::base_opcode()
        {
            if (signedArithmetic) return "blt"s;
            else return "blt.un"s;
        }
    }
}
