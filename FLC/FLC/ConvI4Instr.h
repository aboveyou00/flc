#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvI4Instr : public Instr
        {
        public:
            ConvI4Instr(bool checkOverflow = false, bool fromSigned = true, bool toSigned = true);
            ~ConvI4Instr();

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

//69   conv.i4
//B7   conv.ovf.i4
//84   conv.ovf.i4.un
//6D   conv.u4
//B8   conv.ovf.u4
//88   conv.ovf.u4.un
