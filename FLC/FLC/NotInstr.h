#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NotInstr : public Instr
        {
        public:
            NotInstr();
            ~NotInstr();

            std::string opcode() override;
        };
    }
}

//66   not
