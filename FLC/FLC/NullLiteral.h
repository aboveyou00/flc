#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class NullLiteralRuntimeType : public RuntimeType
            {
            public:
                NullLiteralRuntimeType();
                ~NullLiteralRuntimeType();
            };
        }
    }
}
