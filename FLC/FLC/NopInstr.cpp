#include "stdafx.h"
#include "NopInstr.h"

namespace flc
{
    namespace emit
    {
        NopInstr::NopInstr()
        {
        }
        NopInstr::~NopInstr()
        {
        }

        void NopInstr::stringify(std::stringstream *stream)
        {
            *stream << "nop";
        }
    }
}
