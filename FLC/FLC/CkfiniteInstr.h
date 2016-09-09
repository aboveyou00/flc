#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CkfiniteInstr : public Instr
        {
        public:
            CkfiniteInstr();
            ~CkfiniteInstr();

            std::string opcode() override;
        };
    }
}

//C3   ckfinite
