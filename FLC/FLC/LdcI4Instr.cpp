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

        void LdcI4Instr::stringify(std::stringstream *stream)
        {
            *stream << "ldc.i4";
            switch (value)
            {
            case -1: *stream << ".m1"; break;
            case 0: *stream << ".0"; break;
            case 1: *stream << ".1"; break;
            case 2: *stream << ".2"; break;
            case 3: *stream << ".3"; break;
            case 4: *stream << ".4"; break;
            case 5: *stream << ".5"; break;
            case 6: *stream << ".6"; break;
            case 7: *stream << ".7"; break;
            case 8: *stream << ".8"; break;
            default:
                if (value <= 255) *stream << ".s";
                *stream << " " << value;
            }
        }
    }
}
