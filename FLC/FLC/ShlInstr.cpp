#include "stdafx.h"
#include "ShlInstr.h"

namespace flc
{
    namespace emit
    {
        ShlInstr::ShlInstr()
        {
        }
        ShlInstr::~ShlInstr()
        {
        }

        void ShlInstr::stringify(std::stringstream *stream)
        {
            *stream << "shl";
        }
    }
}
