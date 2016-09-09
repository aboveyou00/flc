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

        std::string ConvI4Instr::opcode()
        {
            if (checkOverflow)
            {
                if (fromSigned)
                {
                    if (toSigned) return "conv.ovf.i4"s;
                    else return "conv.ovf.u4"s;
                }
                else
                {
                    if (toSigned) return "conv.ovf.i4.un"s;
                    else return "conv.ovf.u4.un"s;
                }
            }
            else
            {
                if (toSigned) return "conv.i4"s;
                else return "conv.u4"s;
            }
        }
    }
}
