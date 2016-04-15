#include "stdafx.h"
#include "UInt32.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::uint32()
        {
            static predefined::UInt32RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::UInt32RuntimeType;
            }

            return type;
        }

        namespace predefined
        {
            UInt32RuntimeType::UInt32RuntimeType()
                : RuntimeValueType("System::UInt32")
            {
            }
            UInt32RuntimeType::~UInt32RuntimeType()
            {
            }


        }
    }
}

/*

uint operator +(uint x, uint y);
uint operator -(uint x, uint y);

*/
