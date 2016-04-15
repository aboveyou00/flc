#include "stdafx.h"
#include "Int8.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::int8()
        {
            static predefined::Int8RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::Int8RuntimeType();
            }

            return type;
        }

        namespace predefined
        {
            Int8RuntimeType::Int8RuntimeType()
                : RuntimeValueType("System::Int8")
            {
            }
            Int8RuntimeType::~Int8RuntimeType()
            {
            }


        }
    }
}
