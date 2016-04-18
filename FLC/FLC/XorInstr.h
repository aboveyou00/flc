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

            void stringify(std::stringstream *stream) override;
        };
    }
}

//61   xor
