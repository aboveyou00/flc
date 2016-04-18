#include "stdafx.h"
#include "NotInstr.h"

namespace flc
{
    namespace emit
    {
        NotInstr::NotInstr()
        {
        }
        NotInstr::~NotInstr()
        {
        }

        void NotInstr::stringify(std::stringstream *stream)
        {
            *stream << "not";
        }
    }
}
