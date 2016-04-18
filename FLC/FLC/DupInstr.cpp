#include "stdafx.h"
#include "DupInstr.h"

namespace flc
{
    namespace emit
    {
        DupInstr::DupInstr()
        {
        }
        DupInstr::~DupInstr()
        {
        }

        void DupInstr::stringify(std::stringstream *stream)
        {
            *stream << "dup";
        }
    }
}
