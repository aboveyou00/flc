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
                : RuntimeValueType("System::Char")
            {
            }
            CharRuntimeType::~CharRuntimeType()
            {
            }


        }
    }
}
