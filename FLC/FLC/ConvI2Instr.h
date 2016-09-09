#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvI2Instr : public Instr
        {
        public:
            ConvI2Instr(bool checkOverflow = false, bool fromSigned = true, bool toSigned = true);
            ~ConvI2Instr();

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

//68   conv.i2
//B5   conv.ovf.i2
//83   conv.ovf.i2.un
//D1   conv.u2
//B6   conv.ovf.u2
//87   conv.ovf.u2.un
