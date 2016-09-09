#include "stdafx.h"
#include "RemInstr.h"

namespace flc
{
    namespace emit
    {
        RemInstr::RemInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        RemInstr::~RemInstr()
        {
        }

        bool RemInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string RemInstr::opcode()
        {
            if (signedArithmetic) return "rem"s;
            else return "rem.un"s;
        }
    }
}
