#include "stdafx.h"
#include "Void.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::void0 = new predefined::VoidRuntimeType();

        namespace predefined
        {
            VoidRuntimeType::VoidRuntimeType()
                : RuntimeType("System::Void")
            {
            }
            VoidRuntimeType::~VoidRuntimeType()
            {
            }


        }
    }
}
