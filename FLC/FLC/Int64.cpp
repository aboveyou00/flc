#include "stdafx.h"
#include "Int64.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::int64()
        {
            static predefined::Int64RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::Int64RuntimeType();
            }

            return type;
        }

        namespace predefined
        {
            Int64RuntimeType::Int64RuntimeType()
                : RuntimeValueType("System::Int64")
            {
            }
            Int64RuntimeType::~Int64RuntimeType()
            {
            }


        }
    }
}

/*

long operator +(long x, long y);
long operator -(long x, long y);

*/
