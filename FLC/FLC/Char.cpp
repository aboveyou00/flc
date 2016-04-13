#include "stdafx.h"
#include "Char.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::char16 = new predefined::CharRuntimeType();

        namespace predefined
        {
            CharRuntimeType::CharRuntimeType()
                : RuntimeType("System::Char")
            {
            }
            CharRuntimeType::~CharRuntimeType()
            {
            }


        }
    }
}
