#include "stdafx.h"
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        RuntimeType::RuntimeType(std::string name)
        {
            qualifiedName = name;
        }
        RuntimeType::~RuntimeType()
        {
        }

        std::string RuntimeType::getName()
        {
            auto idx = qualifiedName.find_last_of("::");
            if (idx == -1) return qualifiedName;
            return qualifiedName.substr(idx + 2);
        }
        std::string RuntimeType::getQualifiedName()
        {
            return qualifiedName;
        }

        INameInfo* RuntimeType::resolveName(std::string name, NameType nameType)
        {
            return nullptr;
        }
    }
}
