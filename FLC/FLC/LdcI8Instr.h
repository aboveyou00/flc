#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdcI8Instr : public Instr
        {
        public:
            LdcI8Instr(int64_t constValue);
            ~LdcI8Instr();

            int64_t getConstantValue();

            void stringify(std::stringstream *stream) override;

        private:
            int64_t value;
        };
    }
}

//21 <int64>     ldc.i8 <num>
