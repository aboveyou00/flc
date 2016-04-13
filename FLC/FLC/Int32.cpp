#include "stdafx.h"
#include "Int32.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int32 = new predefined::Int32RuntimeType();

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
