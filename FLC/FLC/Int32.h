#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class Int32RuntimeType : public RuntimeValueType
            {
            public:
                Int32RuntimeType();
                ~Int32RuntimeType();
            };
        }
    }
}
