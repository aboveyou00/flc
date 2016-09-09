#include "stdafx.h"
#include "CeqInstr.h"

namespace flc
{
    namespace emit
    {
        CeqInstr::CeqInstr()
        {
        }
        CeqInstr::~CeqInstr()
        {
        }

        std::string CeqInstr::opcode()
        {
            return "ceq";
        }
    }
}
