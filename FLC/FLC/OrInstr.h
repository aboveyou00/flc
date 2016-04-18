#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class OrInstr : public Instr
        {
        public:
            OrInstr();
            ~OrInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//60   or
