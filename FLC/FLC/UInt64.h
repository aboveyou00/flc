#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class UInt64RuntimeType : public RuntimeValueType
            {
            public:
                UInt64RuntimeType();
                ~UInt64RuntimeType();
            };
        }
    }
}

/*

ulong operator +(ulong x, ulong y);
ulong operator -(ulong x, ulong y);

*/
