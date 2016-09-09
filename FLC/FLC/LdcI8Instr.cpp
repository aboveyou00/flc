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

        std::string LdcI8Instr::opcode()
        {
            return "ldc.i8"s;
        }
        void LdcI8Instr::stringify(std::stringstream *stream)
        {
            Instr::stringify(stream);
            *stream << " " << value;
        }
    }
}
