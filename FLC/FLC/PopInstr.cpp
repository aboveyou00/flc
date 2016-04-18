#include "stdafx.h"
#include "PopInstr.h"

namespace flc
{
    namespace emit
    {
        PopInstr::PopInstr()
        {
        }
        PopInstr::~PopInstr()
        {
        }

        void PopInstr::stringify(std::stringstream *stream)
        {
            *stream << "pop";
        }
    }
}
