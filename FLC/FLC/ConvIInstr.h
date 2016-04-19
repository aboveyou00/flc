#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class ConvIInstr : public Instr
        {
        public:
            ConvIInstr(bool checkOverflow = false, bool fromSigned = true, bool toSigned = true);
            ~ConvIInstr();

            bool checksOverflow();
            bool fromTypeSigned();
            bool toTypeSigned();

            void stringify(std::stringstream *stream) override;

        private:
            bool checkOverflow;
            bool fromSigned, toSigned;
        };
    }
}

//D3   conv.i
//D4   conv.ovf.i
//8A   conv.ovf.i.un
//E0   conv.u
//D5   conv.ovf.u
//8B   conv.ovf.u.un
