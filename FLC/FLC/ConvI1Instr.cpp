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

        std::string ConvI1Instr::opcode()
        {
            if (checkOverflow)
            {
                if (fromSigned)
                {
                    if (toSigned) return "conv.ovf.i1"s;
                    else return "conv.ovf.u1"s;
                }
                else
                {
                    if (toSigned) return "conv.ovf.i1.un"s;
                    else return "conv.ovf.u1.un"s;
                }
            }
            else
            {
                if (toSigned) return "conv.i1"s;
                else return "conv.u1"s;
            }
        }
    }
}
