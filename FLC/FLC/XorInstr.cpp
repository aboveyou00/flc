#include "stdafx.h"
#include "XorInstr.h"

namespace flc
{
    namespace emit
    {
        XorInstr::XorInstr()
        {
        }
        XorInstr::~XorInstr()
        {
        }

        std::string XorInstr::opcode()
        {
            return "xor"s;
        }
    }
}
