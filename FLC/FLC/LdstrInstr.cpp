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

        std::string LdstrInstr::opcode()
        {
            return "ldstr"s;
        }
        void LdstrInstr::stringify(std::stringstream *stream)
        {
            Instr::stringify(stream);
            *stream << " \"" << value << "\"";
        }
    }
}
