#include "stdafx.h"
#include "UInt32.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::uint32 = new predefined::UInt32RuntimeType();

        namespace predefined
        {
            UInt32RuntimeType::UInt32RuntimeType()
                : RuntimeType("System::UInt32")
            {
            }
            UInt32RuntimeType::~UInt32RuntimeType()
            {
            }


        }
    }
}

/*

uint operator +(uint x, uint y);
uint operator -(uint x, uint y);

*/
