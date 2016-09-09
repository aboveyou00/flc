#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvI1Instr : public Instr
        {
        public:
            ConvI1Instr(bool checkOverflow = false, bool fromSigned = true, bool toSigned = true);
            ~ConvI1Instr();

            bool checksOverflow();
            bool fromTypeSigned();
            bool toTypeSigned();

            std::string opcode() override;

        private:
            bool checkOverflow;
            bool fromSigned, toSigned;
        };
    }
}

//67   conv.i1
//B3   conv.ovf.i1
//82   conv.ovf.i1.un
//D2   conv.u1
//B4   conv.ovf.u1
//86   conv.ovf.u1.un
