#include "stdafx.h"
#include "Float.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::float32 = new predefined::FloatRuntimeType();

        namespace predefined
        {
            FloatRuntimeType::FloatRuntimeType()
                : RuntimeValueType("System::Float")
            {
            }
            FloatRuntimeType::~FloatRuntimeType()
            {
            }


        }
    }
}

/*

float operator +(float x, float y);
float operator -(float x, float y);

*/
