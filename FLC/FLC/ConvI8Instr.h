#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvI8Instr : public Instr
        {
        public:
            ConvI8Instr(bool checkOverflow = false, bool fromSigned = true, bool toSigned = true);
            ~ConvI8Instr();

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

//6A   conv.i8
//B9   conv.ovf.i8
//85   conv.ovf.i8.un
//6E   conv.u8
//BA   conv.ovf.u8
//89   conv.ovf.u8.un
