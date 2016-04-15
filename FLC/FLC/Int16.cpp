#include "stdafx.h"
#include "Int16.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::int16()
        {
            static predefined::Int16RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::Int16RuntimeType();
            }

            return type;
        }

        namespace predefined
        {
            Int16RuntimeType::Int16RuntimeType()
                : RuntimeValueType("System::Int16")
            {
            }
            Int16RuntimeType::~Int16RuntimeType()
            {
            }


        }
    }
}
