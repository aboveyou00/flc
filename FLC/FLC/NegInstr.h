#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NegInstr : public Instr
        {
        public:
            NegInstr();
            ~NegInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//65   neg
