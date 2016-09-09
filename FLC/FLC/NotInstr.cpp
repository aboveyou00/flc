#include "stdafx.h"
#include "NotInstr.h"

namespace flc
{
    namespace emit
    {
        NotInstr::NotInstr()
        {
        }
        NotInstr::~NotInstr()
        {
        }

        std::string NotInstr::opcode()
        {
            return "not"s;
        }
    }
}
