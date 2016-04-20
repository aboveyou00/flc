#include "stdafx.h"
#include "LdcR8Instr.h"

namespace flc
{
    namespace emit
    {
        LdcR8Instr::LdcR8Instr(double constValue)
            : value(constValue)
        {
        }
        LdcR8Instr::~LdcR8Instr()
        {
        }

        double LdcR8Instr::getConstantValue()
        {
            return value;
        }

        void LdcR8Instr::stringify(std::stringstream *stream)
        {
            *stream << "ldc.r8 " << value;
        }
    }
}
