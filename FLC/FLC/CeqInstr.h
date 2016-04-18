#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CeqInstr : public Instr
        {
        public:
            CeqInstr();
            ~CeqInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//FE 01   ceq
