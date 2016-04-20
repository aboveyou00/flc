#include "stdafx.h"
#include "ConvI8Instr.h"

namespace flc
{
    namespace emit
    {
        ConvI8Instr::ConvI8Instr(bool checkOverflow, bool fromSigned, bool toSigned)
            : checkOverflow(checkOverflow), fromSigned(fromSigned), toSigned(toSigned)
        {
        }
        ConvI8Instr::~ConvI8Instr()
        {
        }

        bool ConvI8Instr::checksOverflow()
        {
            return checkOverflow;
        }
        bool ConvI8Instr::fromTypeSigned()
        {
            return fromSigned;
        }
        bool ConvI8Instr::toTypeSigned()
        {
            return toSigned;
        }

        void ConvI8Instr::stringify(std::stringstream *stream)
        {
            *stream << "conv.";
            if (checkOverflow) *stream << "ovf.";
            if (fromSigned) *stream << "i";
            else *stream << "u";
            *stream << "8";
            if (checkOverflow && !fromSigned) *stream << ".un";
        }
    }
}
