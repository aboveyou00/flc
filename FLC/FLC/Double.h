#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class DoubleRuntimeType : public RuntimeType
            {
            public:
                DoubleRuntimeType();
                ~DoubleRuntimeType();
            };
        }
    }
}

/*

double operator +(double x, double y);
double operator -(double x, double y);

*/
