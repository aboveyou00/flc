#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvR4Instr : public Instr
        {
        public:
            ConvR4Instr();
            ~ConvR4Instr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//6B   conv.r4
