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

        std::string LdcR4Instr::opcode()
        {
            return "ldc.r4"s;
        }
        void LdcR4Instr::stringify(std::stringstream *stream)
        {
            Instr::stringify(stream);
            *stream << " " << value;
        }
    }
}
