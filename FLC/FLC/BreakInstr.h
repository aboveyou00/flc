#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class BreakInstr : public Instr
        {
        public:
            BreakInstr();
            ~BreakInstr();

            std::string opcode() override;
        };
    }
}

//01   break
