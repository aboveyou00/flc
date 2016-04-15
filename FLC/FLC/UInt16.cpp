#include "stdafx.h"
#include "UInt16.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::uint16()
        {
            static predefined::UInt16RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::UInt16RuntimeType;
            }

            return type;
        }

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
