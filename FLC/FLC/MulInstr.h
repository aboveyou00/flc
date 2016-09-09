#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class MulInstr : public Instr
        {
        public:
            MulInstr(bool checkOverflow = false, bool useSigned = true);
            ~MulInstr();

            bool checksOverflow();
            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool checkOverflow;
            bool signedArithmetic;
        };
    }
}

//5A   mul
//D8   mul.ovf
//D9   mul.ovf.un
