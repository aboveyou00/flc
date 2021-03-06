#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ShrInstr : public Instr
        {
        public:
            ShrInstr(bool useSigned = true);
            ~ShrInstr();

            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool signedArithmetic;
        };
    }
}

//63   shr
//64   shr.un
