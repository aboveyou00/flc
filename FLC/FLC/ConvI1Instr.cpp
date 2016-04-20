#include "stdafx.h"
#include "ConvI1Instr.h"

namespace flc
{
    namespace emit
    {
        ConvI1Instr::ConvI1Instr(bool checkOverflow, bool fromSigned, bool toSigned)
            : checkOverflow(checkOverflow), fromSigned(fromSigned), toSigned(toSigned)
        {
        }
        ConvI1Instr::~ConvI1Instr()
        {
        }

        bool ConvI1Instr::checksOverflow()
        {
            return checkOverflow;
        }
        bool ConvI1Instr::fromTypeSigned()
        {
            return fromSigned;
        }
        bool ConvI1Instr::toTypeSigned()
        {
            return toSigned;
        }

        void ConvI1Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv.";
            if (checkOverflow) *stream << "ovf.";
            if (fromSigned) *stream << "i";
            else *stream << "u";
            *stream << "1";
            if (checkOverflow && !fromSigned) *stream << ".un";
        }
    }
}
