#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class Int8RuntimeType : public RuntimeValueType
            {
            public:
                Int8RuntimeType();
                ~Int8RuntimeType();
            };
        }
    }
}
