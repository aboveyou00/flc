#include "stdafx.h"
#include "UInt16.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint16 = new predefined::UInt16RuntimeType();

        namespace predefined
        {
            UInt16RuntimeType::UInt16RuntimeType()
                : RuntimeValueType("System::UInt16")
            {
            }
            UInt16RuntimeType::~UInt16RuntimeType()
            {
            }


        }
    }
}
