#include "stdafx.h"
#include "LdcI8Instr.h"

namespace flc
{
    namespace emit
    {
        LdcI8Instr::LdcI8Instr(int64_t constValue)
            : value(constValue)
        {
        }
        LdcI8Instr::~LdcI8Instr()
        {
        }

        int64_t LdcI8Instr::getConstantValue()
        {
            return value;
        }

        void LdcI8Instr::stringify(std::stringstream *stream)
        {
            *stream << "ldc.i8  " << value;
        }
    }
}
