#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NegInstr : public Instr
        {
        public:
            NegInstr();
            ~NegInstr();

            std::string opcode() override;
        };
    }
}

//65   neg
