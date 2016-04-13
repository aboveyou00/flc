#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        namespace predefined
        {
            class StringRuntimeType : public RuntimeType
            {
            public:
                StringRuntimeType();
                ~StringRuntimeType();
            };
        }
    }
}

/*

string operator +(string x, string y);
string operator +(string x, object y);
string operator +(object x, string y);

*/
