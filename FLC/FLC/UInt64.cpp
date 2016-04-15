#include "stdafx.h"
#include "UInt64.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::uint64()
        {
            static predefined::UInt64RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::UInt64RuntimeType;
            }

            return type;
        }

        namespace predefined
        {
            UInt64RuntimeType::UInt64RuntimeType()
                : RuntimeValueType("System::UInt64")
            {
            }
            UInt64RuntimeType::~UInt64RuntimeType()
            {
            }


        }
    }
}

/*

ulong operator +(ulong x, ulong y);
ulong operator -(ulong x, ulong y);

*/
