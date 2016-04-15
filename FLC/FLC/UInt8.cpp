#include "stdafx.h"
#include "UInt8.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::uint8()
        {
            static predefined::UInt8RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::UInt8RuntimeType;
            }

            return type;
        }

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
