#include "stdafx.h"
#include "Char.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::char16()
        {
            static predefined::CharRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::CharRuntimeType();
            }

            return type;
        }

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
