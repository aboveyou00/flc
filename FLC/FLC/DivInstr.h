#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class DivInstr : public Instr
        {
        public:
            DivInstr(bool useSigned = true);
            ~DivInstr();

            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool signedArithmetic;
        };
    }
}

//5B   div
//5C   div.un
