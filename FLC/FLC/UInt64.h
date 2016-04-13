#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class UInt64RuntimeType : public RuntimeType
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
