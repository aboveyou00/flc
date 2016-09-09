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

        std::string ConvI8Instr::opcode()
        {
            if (checkOverflow)
            {
                if (fromSigned)
                {
                    if (toSigned) return "conv.ovf.i8"s;
                    else return "conv.ovf.u8"s;
                }
                else
                {
                    if (toSigned) return "conv.ovf.i8.un"s;
                    else return "conv.ovf.u8.un"s;
                }
            }
            else
            {
                if (toSigned) return "conv.i8"s;
                else return "conv.u8"s;
            }
        }
    }
}
