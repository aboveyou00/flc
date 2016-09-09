#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class AddInstr : public Instr
        {
        public:
            AddInstr(bool checkOverflow = false, bool useSigned = true);
            ~AddInstr();

            bool checksOverflow();
            bool usesSignedArithmetic();

            std::string opcode() override;

        private:
            bool checkOverflow;
            bool signedArithmetic;
        };
    }
}

//58   add
//D6   add.ovf
//D7   add.ovf.un
