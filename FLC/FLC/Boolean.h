#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class BooleanRuntimeType : public RuntimeValueType
            {
            public:
                BooleanRuntimeType();
                ~BooleanRuntimeType();
            };
        }
    }
}
