#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class XorInstr : public Instr
        {
        public:
            XorInstr();
            ~XorInstr();

            std::string opcode() override;
        };
    }
}

//61   xor
