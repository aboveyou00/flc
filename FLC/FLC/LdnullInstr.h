#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdnullInstr : public Instr
        {
        public:
            LdnullInstr();
            ~LdnullInstr();

            std::string opcode() override;
        };
    }
}

//14   ldnull
