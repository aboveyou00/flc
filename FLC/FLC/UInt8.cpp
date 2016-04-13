#include "stdafx.h"
#include "UInt8.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint8 = new predefined::UInt8RuntimeType();

        namespace predefined
        {
            UInt8RuntimeType::UInt8RuntimeType()
                : RuntimeValueType("System::UInt8")
            {
            }
            UInt8RuntimeType::~UInt8RuntimeType()
            {
            }


        }
    }
}
