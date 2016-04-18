#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class BreakInstr : public Instr
        {
        public:
            BreakInstr();
            ~BreakInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//01   break
