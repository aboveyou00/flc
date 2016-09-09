#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CeqInstr : public Instr
        {
        public:
            CeqInstr();
            ~CeqInstr();

            std::string opcode() override;
        };
    }
}

//FE 01   ceq
