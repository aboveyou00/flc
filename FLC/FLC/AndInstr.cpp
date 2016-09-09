#include "stdafx.h"
#include "AndInstr.h"

namespace flc
{
    namespace emit
    {
        AndInstr::AndInstr()
        {
        }
        AndInstr::~AndInstr()
        {
        }

        std::string AndInstr::opcode()
        {
            return "and"s;
        }
    }
}
