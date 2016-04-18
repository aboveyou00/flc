#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class PopInstr : public Instr
        {
        public:
            PopInstr();
            ~PopInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//26   pop
