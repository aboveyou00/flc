#include "stdafx.h"
#include "Double.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::float64()
        {
            static predefined::DoubleRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::DoubleRuntimeType();
            }

            return type;
        }

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
