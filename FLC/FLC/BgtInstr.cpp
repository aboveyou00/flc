#include "stdafx.h"
#include "BgtInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BgtInstr::BgtInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BgtInstr::~BgtInstr()
        {
        }

        bool BgtInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }
        
        std::string BgtInstr::base_opcode()
        {
            if (signedArithmetic) return "bgt"s;
            else return "bgt.un"s;
        }
    }
}
