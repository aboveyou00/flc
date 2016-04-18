#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdnullInstr : public Instr
        {
        public:
            LdnullInstr();
            ~LdnullInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//14   ldnull
