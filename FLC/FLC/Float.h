#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class FloatRuntimeType : public RuntimeValueType
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
