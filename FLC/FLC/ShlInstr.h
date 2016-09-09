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

            std::string opcode() override;
        };
    }
}

//62   shl
