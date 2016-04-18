#include "stdafx.h"
#include "CeqInstr.h"

namespace flc
{
    namespace emit
    {
        CeqInstr::CeqInstr()
        {
        }
        CeqInstr::~CeqInstr()
        {
        }

        void CeqInstr::stringify(std::stringstream *stream)
        {
            *stream << "ceq";
        }
    }
}
