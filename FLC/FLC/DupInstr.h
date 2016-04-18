#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class DupInstr : public Instr
        {
        public:
            DupInstr();
            ~DupInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//25   dup
