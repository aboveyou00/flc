#include "stdafx.h"
#include "UInt32.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint64 = new RuntimeType("System::UInt64");

        namespace predefined
        {

        }
    }
}

/*

ulong operator +(ulong x, ulong y);
ulong operator -(ulong x, ulong y);

*/
