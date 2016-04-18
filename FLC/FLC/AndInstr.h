#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class AndInstr : public Instr
        {
        public:
            AndInstr();
            ~AndInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//5F   and
