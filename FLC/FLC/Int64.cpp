#include "stdafx.h"
#include "Int64.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int64 = new RuntimeType("System::Int64");

        namespace predefined
        {

        }
    }
}

/*

long operator +(long x, long y);
long operator -(long x, long y);

*/
