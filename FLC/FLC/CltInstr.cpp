#include "stdafx.h"
#include "CltInstr.h"

namespace flc
{
    namespace emit
    {
        CltInstr::CltInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        CltInstr::~CltInstr()
        {
        }

        bool CltInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string CltInstr::opcode()
        {
            if (signedArithmetic) return "clt"s;
            else return "clt.un"s;
        }
    }
}
