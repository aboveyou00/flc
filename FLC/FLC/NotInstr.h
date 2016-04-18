#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class NotInstr : public Instr
        {
        public:
            NotInstr();
            ~NotInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//66   not
