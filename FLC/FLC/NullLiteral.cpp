#include "stdafx.h"
#include "NullLiteral.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::nullLiteral = new predefined::NullLiteralRuntimeType();

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
