#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class BooleanRuntimeType : public RuntimeType
            {
            public:
                BooleanRuntimeType();
                ~BooleanRuntimeType();
            };
        }
    }
}
