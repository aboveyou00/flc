#include "stdafx.h"
#include "LdnullInstr.h"

namespace flc
{
    namespace emit
    {
        LdnullInstr::LdnullInstr()
        {
        }
        LdnullInstr::~LdnullInstr()
        {
        }

        std::string LdnullInstr::opcode()
        {
            return "ldnull";
        }
    }
}
