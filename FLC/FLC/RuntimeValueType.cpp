#include "stdafx.h"
#include "RuntimeValueType.h"

namespace flc
{
    namespace types
    {
        RuntimeValueType::RuntimeValueType(std::string name)
            : RuntimeType(name)
        {
        }
        RuntimeValueType::~RuntimeValueType()
        {
        }

        bool RuntimeValueType::isReferenceType()
        {
            return false;
        }
        bool RuntimeValueType::isValueType()
        {
            return true;
        }
    }
}
