#include "stdafx.h"
#include "LdcR4Instr.h"

namespace flc
{
    namespace emit
    {
        LdcR4Instr::LdcR4Instr(float constValue)
            : value(constValue)
        {
        }
        LdcR4Instr::~LdcR4Instr()
        {
        }

        float LdcR4Instr::getConstantValue()
        {
            return value;
        }

        void LdcR4Instr::stringify(std::stringstream *stream)
        {
            *stream << "ldc.r4  " << value;
        }
    }
}
