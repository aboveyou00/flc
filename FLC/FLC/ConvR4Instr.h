#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvR4Instr : public Instr
        {
        public:
            ConvR4Instr();
            ~ConvR4Instr();

            std::string opcode() override;
        };
    }
}

//6B   conv.r4
