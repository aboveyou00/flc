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

        void ConvR8Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv.r8";
        }
    }
}
