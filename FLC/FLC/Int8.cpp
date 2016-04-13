#include "stdafx.h"
#include "Int8.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int8 = new predefined::Int8RuntimeType();

        namespace predefined
        {
            Int8RuntimeType::Int8RuntimeType()
                : RuntimeType("System::Int8")
            {
            }
            Int8RuntimeType::~Int8RuntimeType()
            {
            }


        }
    }
}
