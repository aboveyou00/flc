#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class DupInstr : public Instr
        {
        public:
            DupInstr();
            ~DupInstr();

            std::string opcode() override;
        };
    }
}

//25   dup
