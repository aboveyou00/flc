#include "stdafx.h"
#include "ConvR4Instr.h"

namespace flc
{
    namespace emit
    {
        ConvR4Instr::ConvR4Instr()
        {
        }
        ConvR4Instr::~ConvR4Instr()
        {
        }

        std::string ConvR4Instr::opcode()
        {
            return "conv.r4";
        }
    }
}
