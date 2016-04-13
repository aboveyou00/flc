#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class UInt32RuntimeType : public RuntimeType
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
