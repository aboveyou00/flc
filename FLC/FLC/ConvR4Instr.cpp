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

        void ConvR4Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv.r4";
        }
    }
}
