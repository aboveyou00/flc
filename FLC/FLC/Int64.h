#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class Int64RuntimeType : public RuntimeValueType
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
