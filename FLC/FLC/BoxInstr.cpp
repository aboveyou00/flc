#include "stdafx.h"
#include "BoxInstr.h"

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

        void BoxInstr::stringify(stringstream *stream)
        {
            *stream << "box " << boxType->getQualifiedName();
        }
    }
}
