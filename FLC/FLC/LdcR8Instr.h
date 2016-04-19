#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdcR8Instr : public Instr
        {
        public:
            LdcR8Instr(double constValue);
            ~LdcR8Instr();

            double getConstantValue();

            void stringify(std::stringstream *stream) override;

        private:
            double value;
        };
    }
}

//23 <float64>   ldc.r8 <num>
