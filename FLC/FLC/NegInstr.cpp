#include "stdafx.h"
#include "NegInstr.h"

namespace flc
{
    namespace emit
    {
        NegInstr::NegInstr()
        {
        }
        NegInstr::~NegInstr()
        {
        }

        std::string NegInstr::opcode()
        {
            return "neg"s;
        }
    }
}
