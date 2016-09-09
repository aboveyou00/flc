#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class RemInstr : public Instr
        {
        public:
            RemInstr(bool useSigned = true);
            ~RemInstr();

            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool signedArithmetic;
        };
    }
}

//5D   rem
//5E   rem.un
