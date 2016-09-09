#include "stdafx.h"
#include "ConvR8Instr.h"

namespace flc
{
    namespace emit
    {
        ConvR8Instr::ConvR8Instr()
        {
        }
        ConvR8Instr::~ConvR8Instr()
        {
        }

        std::string ConvR8Instr::opcode()
        {
            return "conv.r8";
        }
    }
}
