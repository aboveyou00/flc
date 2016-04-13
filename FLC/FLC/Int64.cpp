#include "stdafx.h"
#include "Int64.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int64 = new predefined::Int64RuntimeType();

        namespace predefined
        {
            Int64RuntimeType::Int64RuntimeType()
                : RuntimeType("System::Int64")
            {
            }
            Int64RuntimeType::~Int64RuntimeType()
            {
            }


        }
    }
}

/*

long operator +(long x, long y);
long operator -(long x, long y);

*/
