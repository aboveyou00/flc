#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdcI4Instr : public Instr
        {
        public:
            LdcI4Instr(int32_t constValue);
            ~LdcI4Instr();

            int32_t getConstantValue();

            void stringify(std::stringstream *stream) override;

        private:
            int32_t value;
        };
    }
}

//20 <int32>   ldc.i4 <num>
//1F <int8>    ldc.i4.s <num>
//15           ldc.i4.m1
//16           ldc.i4.0
//17           ldc.i4.1
//18           ldc.i4.2
//19           ldc.i4.3
//20           ldc.i4.4
//21           ldc.i4.5
//22           ldc.i4.6
//23           ldc.i4.7
//24           ldc.i4.8
