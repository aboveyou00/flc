#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class Int64RuntimeType : public RuntimeType
            {
            public:
                Int64RuntimeType();
                ~Int64RuntimeType();
            };
        }
    }
}

/*

long operator +(long x, long y);
long operator -(long x, long y);

*/
