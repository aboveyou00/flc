#include "stdafx.h"
#include "NullLiteral.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::nullLiteral()
        {
            static predefined::NullLiteralRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::NullLiteralRuntimeType;
            }

            return type;
        }

        namespace predefined
        {
            NullLiteralRuntimeType::NullLiteralRuntimeType()
                : RuntimeType("%%NULL%%")
            {
            }
            NullLiteralRuntimeType::~NullLiteralRuntimeType()
            {
            }


        }
    }
}
