#include "stdafx.h"
#include "Int32.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::int32()
        {
            static predefined::Int32RuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::Int32RuntimeType();
            }

            return type;
        }

        namespace predefined
        {
            Int32RuntimeType::Int32RuntimeType()
                : RuntimeValueType("System::Int32")
            {
            }
            Int32RuntimeType::~Int32RuntimeType()
            {
            }


        }
    }
}

/*

int operator +(int x, int y);
int operator -(int x, int y);

*/
