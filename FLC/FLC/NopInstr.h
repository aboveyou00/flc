#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NopInstr : public Instr
        {
        public:
            NopInstr();
            ~NopInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//00   nop
