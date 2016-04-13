#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class UInt32RuntimeType : public RuntimeValueType
            {
            public:
                UInt32RuntimeType();
                ~UInt32RuntimeType();
            };
        }
    }
}

/*

uint operator +(uint x, uint y);
uint operator -(uint x, uint y);

*/
