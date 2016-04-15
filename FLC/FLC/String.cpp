#include "stdafx.h"
#include "String.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::string()
        {
            static predefined::StringRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::StringRuntimeType;
            }

            return type;
        }

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
