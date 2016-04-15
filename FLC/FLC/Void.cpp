#include "stdafx.h"
#include "Void.h"

namespace flc
{
    namespace types
    {
        RuntimeType *RuntimeType::void0()
        {
            static predefined::VoidRuntimeType *type = nullptr;
            if (type == nullptr)
            {
                type = new predefined::VoidRuntimeType;
            }

            return type;
        }

        namespace predefined
        {
            VoidRuntimeType::VoidRuntimeType()
                : RuntimeType("System::Void")
            {
            }
            VoidRuntimeType::~VoidRuntimeType()
            {
            }

            bool VoidRuntimeType::isReferenceType()
            {
                return false;
            }
            bool VoidRuntimeType::isValueType()
            {
                return false;
            }
        }
    }
}
