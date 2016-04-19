#include "stdafx.h"
#include "ConvI2Instr.h"

namespace flc
{
    namespace emit
    {
        ConvI2Instr::ConvI2Instr(bool checkOverflow, bool fromSigned, bool toSigned)
            : checkOverflow(checkOverflow), fromSigned(fromSigned), toSigned(toSigned)
        {
        }
        ConvI2Instr::~ConvI2Instr()
        {
        }

        bool ConvI2Instr::checksOverflow()
        {
            return checkOverflow;
        }
        bool ConvI2Instr::fromTypeSigned()
        {
            return fromSigned;
        }
        bool ConvI2Instr::toTypeSigned()
        {
            return toSigned;
        }

        void ConvI2Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv";
            if (checkOverflow) *stream << ".ovf";
            if (fromSigned) *stream << "i";
            else *stream << "u";
            *stream << "2";
            if (checkOverflow && !fromSigned) *stream << ".un";
        }
    }
}
