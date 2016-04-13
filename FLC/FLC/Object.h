#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class ObjectRuntimeType : public RuntimeType
            {
            public:
                ObjectRuntimeType();
                ~ObjectRuntimeType();
            };
        }
    }
}
