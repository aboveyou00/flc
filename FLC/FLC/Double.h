#pragma once
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class DoubleRuntimeType : public RuntimeValueType
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
