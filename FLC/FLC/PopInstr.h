#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class PopInstr : public Instr
        {
        public:
            PopInstr();
            ~PopInstr();

            std::string opcode() override;
        };
    }
}

//26   pop
