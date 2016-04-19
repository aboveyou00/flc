#include "stdafx.h"
#include "ConvIInstr.h"

namespace flc
{
    namespace emit
    {
        ConvIInstr::ConvIInstr(bool checkOverflow, bool fromSigned, bool toSigned)
            : checkOverflow(checkOverflow), fromSigned(fromSigned), toSigned(toSigned)
        {
        }
        ConvIInstr::~ConvIInstr()
        {
        }

        bool ConvIInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool ConvIInstr::fromTypeSigned()
        {
            return fromSigned;
        }
        bool ConvIInstr::toTypeSigned()
        {
            return toSigned;
        }

        void ConvIInstr::stringify(std::stringstream *stream)
        {
            *stream << "conv";
            if (checkOverflow) *stream << ".ovf";
            if (fromSigned) *stream << "i";
            else *stream << "u";
            if (checkOverflow && !fromSigned) *stream << ".un";
        }
    }
}
