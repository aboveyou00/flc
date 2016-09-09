#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class AndInstr : public Instr
        {
        public:
            AndInstr();
            ~AndInstr();

            std::string opcode() override;
        };
    }
}

//5F   and
