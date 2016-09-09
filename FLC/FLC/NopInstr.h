#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NopInstr : public Instr
        {
        public:
            NopInstr();
            ~NopInstr();

            std::string opcode() override;
        };
    }
}

//00   nop
