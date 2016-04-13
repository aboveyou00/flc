#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class FloatRuntimeType : public RuntimeType
            {
            public:
                FloatRuntimeType();
                ~FloatRuntimeType();
            };
        }
    }
}

/*

float operator +(float x, float y);
float operator -(float x, float y);

*/
