#include "stdafx.h"
#include "CkfiniteInstr.h"

namespace flc
{
    namespace emit
    {
        CkfiniteInstr::CkfiniteInstr()
        {
        }
        CkfiniteInstr::~CkfiniteInstr()
        {
        }

        std::string CkfiniteInstr::opcode()
        {
            return "ckfinite";
        }
    }
}
