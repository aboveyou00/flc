#include "stdafx.h"
#include "Boolean.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::bool8 = new predefined::BooleanRuntimeType();

        namespace predefined
        {
            BooleanRuntimeType::BooleanRuntimeType()
                : RuntimeType("System::Boolean")
            {
            }
            BooleanRuntimeType::~BooleanRuntimeType()
            {
            }


        }
    }
}
