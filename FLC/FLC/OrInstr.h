#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class OrInstr : public Instr
        {
        public:
            OrInstr();
            ~OrInstr();

            std::string opcode() override;
        };
    }
}

//60   or
