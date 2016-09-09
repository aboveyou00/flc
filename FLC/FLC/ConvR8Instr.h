#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvR8Instr : public Instr
        {
        public:
            ConvR8Instr();
            ~ConvR8Instr();

            std::string opcode() override;
        };
    }
}

//6C   conv.r8
