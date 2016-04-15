#include "stdafx.h"
#include "Boolean.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::bool8()
        {
            static predefined::BooleanRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::BooleanRuntimeType();
            }

            return type;
        }

        namespace predefined
        {
            BooleanRuntimeType::BooleanRuntimeType()
                : RuntimeValueType("System::Boolean")
            {
            }
            BooleanRuntimeType::~BooleanRuntimeType()
            {
            }


        }
    }
}
