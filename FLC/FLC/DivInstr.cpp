#include "stdafx.h"
#include "DivInstr.h"

namespace flc
{
    namespace emit
    {
        DivInstr::DivInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        DivInstr::~DivInstr()
        {
        }

        bool DivInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string DivInstr::opcode()
        {
            if (signedArithmetic) return "div"s;
            else return "div.un"s;
        }
    }
}
