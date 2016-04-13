#include "stdafx.h"
#include "String.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::string = new predefined::StringRuntimeType();

        namespace predefined
        {
            StringRuntimeType::StringRuntimeType()
                : RuntimeType("System::String")
            {
            }
            StringRuntimeType::~StringRuntimeType()
            {
            }


        }
    }
}

/*

string operator +(string x, string y);
string operator +(string x, object y);
string operator +(object x, string y);

*/
