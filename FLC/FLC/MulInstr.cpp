#include "stdafx.h"
#include "MulInstr.h"

namespace flc
{
    namespace emit
    {
        MulInstr::MulInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        MulInstr::~MulInstr()
        {
        }

        bool MulInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool MulInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string MulInstr::opcode()
        {
            if (checkOverflow)
            {
                if (signedArithmetic) return "mul.ovf"s;
                else return "mul.ovf.un"s;
            }
            else return "mul"s;
        }
    }
}
