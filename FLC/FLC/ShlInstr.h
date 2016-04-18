#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ShlInstr : public Instr
        {
        public:
            ShlInstr();
            ~ShlInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//62   shl
