#include "stdafx.h"
#include "AddInstr.h"

namespace flc
{
    namespace emit
    {
        AddInstr::AddInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        AddInstr::~AddInstr()
        {
        }

        bool AddInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool AddInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        std::string AddInstr::opcode()
        {
            if (checkOverflow)
            {
                if (signedArithmetic) return "add.ovf"s;
                else return "add.ovf.un"s;
            }
            else return "add"s;
        }
    }
}
