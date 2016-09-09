#include "stdafx.h"
#include "ShrInstr.h"

namespace flc
{
    namespace emit
    {
        ShrInstr::ShrInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        ShrInstr::~ShrInstr()
        {
        }

        bool ShrInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string ShrInstr::opcode()
        {
            if (signedArithmetic) return "shr"s;
            else return "shr.un"s;
        }
    }
}
