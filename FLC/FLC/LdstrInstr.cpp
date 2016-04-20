#include "stdafx.h"
#include "LdstrInstr.h"

namespace flc
{
    namespace emit
    {
        LdstrInstr::LdstrInstr(string value)
            : value(value)
        {
        }
        LdstrInstr::~LdstrInstr()
        {
        }

        string LdstrInstr::getValue()
        {
            return value;
        }

        void LdstrInstr::stringify(std::stringstream *stream)
        {
            *stream << "ldstr \"" << value << "\"";
        }
    }
}
