#include "stdafx.h"
#include "Double.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::float64 = new RuntimeType("System::Double");

        namespace predefined
        {

        }
    }
}

/*

double operator +(double x, double y);
double operator -(double x, double y);

*/
