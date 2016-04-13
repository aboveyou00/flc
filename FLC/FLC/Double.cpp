#include "stdafx.h"
#include "Double.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::float64 = new predefined::DoubleRuntimeType();

        namespace predefined
        {
            DoubleRuntimeType::DoubleRuntimeType()
                : RuntimeValueType("System::Double")
            {
            }
            DoubleRuntimeType::~DoubleRuntimeType()
            {
            }


        }
    }
}

/*

double operator +(double x, double y);
double operator -(double x, double y);

*/
