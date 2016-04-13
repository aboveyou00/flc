#include "stdafx.h"
#include "UInt64.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint64 = new predefined::UInt64RuntimeType();

        namespace predefined
        {
            UInt64RuntimeType::UInt64RuntimeType()
                : RuntimeType("System::UInt64")
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
