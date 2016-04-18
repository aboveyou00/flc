#include "stdafx.h"
#include "XorInstr.h"

namespace flc
{
    namespace emit
    {
        XorInstr::XorInstr()
        {
        }
        XorInstr::~XorInstr()
        {
        }

        void XorInstr::stringify(std::stringstream *stream)
        {
            *stream << "xor";
        }
    }
}
