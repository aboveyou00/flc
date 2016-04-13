#include "stdafx.h"
#include "Int16.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int16 = new predefined::Int16RuntimeType();

        namespace predefined
        {
            Int16RuntimeType::Int16RuntimeType()
                : RuntimeType("System::Int16")
            {
            }
            Int16RuntimeType::~Int16RuntimeType()
            {
            }


        }
    }
}
