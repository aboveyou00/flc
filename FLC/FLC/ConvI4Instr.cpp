#include "stdafx.h"
#include "ConvI4Instr.h"

namespace flc
{
    namespace emit
    {
        ConvI4Instr::ConvI4Instr(bool checkOverflow, bool fromSigned, bool toSigned)
            : checkOverflow(checkOverflow), fromSigned(fromSigned), toSigned(toSigned)
        {
        }
        ConvI4Instr::~ConvI4Instr()
        {
        }

        bool ConvI4Instr::checksOverflow()
        {
            return checkOverflow;
        }
        bool ConvI4Instr::fromTypeSigned()
        {
            return fromSigned;
        }
        bool ConvI4Instr::toTypeSigned()
        {
            return toSigned;
        }

        void ConvI4Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv.";
            if (checkOverflow) *stream << "ovf.";
            if (fromSigned) *stream << "i";
            else *stream << "u";
            *stream << "4";
            if (checkOverflow && !fromSigned) *stream << ".un";
        }
    }
}
