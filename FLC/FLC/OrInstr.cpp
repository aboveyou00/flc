#include "stdafx.h"
#include "OrInstr.h"

namespace flc
{
    namespace emit
    {
        OrInstr::OrInstr()
        {
        }
        OrInstr::~OrInstr()
        {
        }

        void OrInstr::stringify(std::stringstream *stream)
        {
            *stream << "or";
        }
    }
}
