#include "stdafx.h"
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        Instr::Instr()
        {
        }
        Instr::~Instr()
        {
        }

        std::string Instr::toString()
        {
            stringstream stream;
            stringify(&stream);
            return stream.str();
        }
    }
}
