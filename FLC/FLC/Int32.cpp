#include "stdafx.h"
#include "Int32.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::int32 = new RuntimeType("System::Int32");

        namespace predefined
        {

        }
    }
}

/*

int operator +(int x, int y);
int operator -(int x, int y);

*/
