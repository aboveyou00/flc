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

        void LdnullInstr::stringify(std::stringstream *stream)
        {
            *stream << "ldnull";
        }
    }
}
