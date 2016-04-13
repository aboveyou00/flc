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

        INameInfo* RuntimeType::resolveName(std::string name, NameType nameType)
        {
            return nullptr;
        }

        std::string RuntimeType::getName()
        {
            auto idx = qualifiedName.find_last_of("::") - 1;
            if (idx == -1) return qualifiedName;
            return qualifiedName.substr(idx + 2);
        }
        std::string RuntimeType::getQualifiedName()
        {
            return qualifiedName;
        }

        bool RuntimeType::isSameAs(RuntimeType* other)
        {
            return RuntimeType::areSameType(this, other);
        }
        bool RuntimeType::areSameType(RuntimeType* one, RuntimeType* two)
        {
            if (one == nullptr || two == nullptr) return false;
            if (one == two) return true;
            if (one->getQualifiedName().compare(two->getQualifiedName()) == 0) return true;
            return false;
        }
    }
}
