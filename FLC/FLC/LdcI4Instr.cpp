#include "stdafx.h"
#include "LdcI4Instr.h"

namespace flc
{
    namespace emit
    {
        LdcI4Instr::LdcI4Instr(int32_t constValue)
            : value(constValue)
        {
        }
        LdcI4Instr::~LdcI4Instr()
        {
        }

        int32_t LdcI4Instr::getConstantValue()
        {
            return value;
        }

        std::string LdcI4Instr::opcode()
        {
            switch (value)
            {
            case -1: return "ldc.i4.m1"s;
            case 0: return "ldc.i4.0"s;
            case 1: return "ldc.i4.1"s;
            case 2: return "ldc.i4.2"s;
            case 3: return "ldc.i4.3"s;
            case 4: return "ldc.i4.4"s;
            case 5: return "ldc.i4.5"s;
            case 6: return "ldc.i4.6"s;
            case 7: return "ldc.i4.7"s;
            case 8: return "ldc.i4.8"s;
            default:
                if (value <= 255) return "ldc.i4.s"s;
                return "ldc.i4"s;
            }
        }
        void LdcI4Instr::stringify(std::stringstream *stream)
        {
            Instr::stringify(stream);
            if (value < -1 || value > 8) *stream << " " << value;
        }
    }
}
