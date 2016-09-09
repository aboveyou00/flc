#include "stdafx.h"
#include "SubInstr.h"

namespace flc
{
    namespace emit
    {
        SubInstr::SubInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        SubInstr::~SubInstr()
        {
        }

        bool SubInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool SubInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string SubInstr::opcode()
        {
            if (checkOverflow)
            {
                if (signedArithmetic) return "sub.ovf"s;
                else return "sub.ovf.un"s;
            }
            else return "sub"s;
        }
    }
}
