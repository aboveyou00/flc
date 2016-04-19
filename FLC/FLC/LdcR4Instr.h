#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdcR4Instr : public Instr
        {
        public:
            LdcR4Instr(float constValue);
            ~LdcR4Instr();

            float getConstantValue();

            void stringify(std::stringstream *stream) override;

        private:
            float value;
        };
    }
}

//22 <float32>   ldc.r4 <num>
