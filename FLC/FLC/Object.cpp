#include "stdafx.h"
#include "Object.h"

namespace flc
{
    namespace types
    {
        RuntimeType* const RuntimeType::object = new predefined::ObjectRuntimeType();

        namespace predefined
        {
            ObjectRuntimeType::ObjectRuntimeType()
                : RuntimeType("System::Object")
            {
            }
            ObjectRuntimeType::~ObjectRuntimeType()
            {
            }


        }
    }
}
