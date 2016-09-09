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

        std::string ConvIInstr::opcode()
        {
            if (checkOverflow)
            {
                if (fromSigned)
                {
                    if (toSigned) return "conv.ovf.i"s;
                    else return "conv.ovf.u"s;
                }
                else
                {
                    if (toSigned) return "conv.ovf.i.un"s;
                    else return "conv.ovf.u.un"s;
                }
            }
            else
            {
                if (toSigned) return "conv.i"s;
                else return "conv.u"s;
            }
        }
    }
}
