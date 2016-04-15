#include "stdafx.h"
#include "Object.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::object()
        {
            static predefined::ObjectRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::ObjectRuntimeType;
            }

            return type;
        }

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
