#include "stdafx.h"
#include "CkfiniteInstr.h"

namespace flc
{
    namespace emit
    {
        CkfiniteInstr::CkfiniteInstr()
        {
        }
        CkfiniteInstr::~CkfiniteInstr()
        {
        }

        void CkfiniteInstr::stringify(std::stringstream *stream)
        {
            *stream << "ckfinite";
        }
    }
}
