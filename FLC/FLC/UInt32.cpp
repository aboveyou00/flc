#include "stdafx.h"
#include "UInt32.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint32 = new RuntimeType("System::UInt32");

        namespace predefined
        {

        }
    }
}

/*

uint operator +(uint x, uint y);
uint operator -(uint x, uint y);

*/
