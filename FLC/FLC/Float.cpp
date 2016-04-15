#include "stdafx.h"
#include "Float.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::float32()
        {
            static predefined::FloatRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::FloatRuntimeType();
            }

            return type;
        }

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
