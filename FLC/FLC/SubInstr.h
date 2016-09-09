#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class SubInstr : public Instr
        {
        public:
            SubInstr(bool checkOverflow = false, bool useSigned = true);
            ~SubInstr();

            bool checksOverflow();
            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool checkOverflow;
            bool signedArithmetic;
        };
    }
}

//59   sub
//DA   sub.ovf
//DB   sub.ovf.un
