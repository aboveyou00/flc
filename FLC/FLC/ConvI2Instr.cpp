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

        std::string ConvI2Instr::opcode()
        {
            if (checkOverflow)
            {
                if (fromSigned)
                {
                    if (toSigned) return "conv.ovf.i2"s;
                    else return "conv.ovf.u2"s;
                }
                else
                {
                    if (toSigned) return "conv.ovf.i2.un"s;
                    else return "conv.ovf.u2.un"s;
                }
            }
            else
            {
                if (toSigned) return "conv.i2"s;
                else return "conv.u2"s;
            }
        }
    }
}
