#include "stdafx.h"
#include "Float.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::float32 = new RuntimeType("System::Float");

        namespace predefined
        {

        }
    }
}

/*

float operator +(float x, float y);
float operator -(float x, float y);

*/
