#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CkfiniteInstr : public Instr
        {
        public:
            CkfiniteInstr();
            ~CkfiniteInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//C3   ckfinite
