#include "stdafx.h"
#include "NegInstr.h"

namespace flc
{
    namespace emit
    {
        NegInstr::NegInstr()
        {
        }
        NegInstr::~NegInstr()
        {
        }

        void NegInstr::stringify(std::stringstream *stream)
        {
            *stream << "neg";
        }
    }
}
