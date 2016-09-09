#include "stdafx.h"
#include "ShlInstr.h"

namespace flc
{
    namespace emit
    {
        ShlInstr::ShlInstr()
        {
        }
        ShlInstr::~ShlInstr()
        {
        }

        std::string ShlInstr::opcode()
        {
            return "shl"s;
        }
    }
}
