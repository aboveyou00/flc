#include "stdafx.h"
#include "CgtInstr.h"

namespace flc
{
    namespace emit
    {
        CgtInstr::CgtInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        CgtInstr::~CgtInstr()
        {
        }

        bool CgtInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string CgtInstr::opcode()
        {
            if (signedArithmetic) return "cgt"s;
            else return "cgt.s"s;
        }
    }
}
