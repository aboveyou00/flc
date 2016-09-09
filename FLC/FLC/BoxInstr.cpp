#include "stdafx.h"
#include "BoxInstr.h"
#include "RuntimeType.h"

namespace flc
{
    namespace emit
    {
        BoxInstr::BoxInstr(types::RuntimeType *type)
            : boxType(type)
        {
        }
        BoxInstr::~BoxInstr()
        {
        }

        types::RuntimeType *BoxInstr::getBoxType()
        {
            return boxType;
        }

        std::string BoxInstr::opcode()
        {
            return "box";
        }
        void BoxInstr::stringify(stringstream *stream)
        {
            Instr::stringify(stream);
            *stream << " " << boxType->getQualifiedName();
        }
    }
}
