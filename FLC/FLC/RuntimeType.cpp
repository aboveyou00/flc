#include "stdafx.h"
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        RuntimeType::RuntimeType(std::string name)
            : _qualifiedName(name)
        {
        }
        RuntimeType::~RuntimeType()
        {
        }

        IMemberInfo* RuntimeType::resolveName(std::string name, NameType nameType)
        {
            for (size_t q = 0; q < _members.size(); q++)
            {
                auto member = _members[q];
                if (member->matchesSelector(name, nameType)) return member;
            }
            return nullptr;
        }

        std::string RuntimeType::getName()
        {
            auto idx = _qualifiedName.find_last_of("::");
            if (idx == -1) return _qualifiedName;
            return _qualifiedName.substr(idx + 1);
        }
        std::string RuntimeType::getQualifiedName()
        {
            return _qualifiedName;
        }

        bool RuntimeType::isVoid()
        {
            return false;
        }
        bool RuntimeType::isNull()
        {
            return false;
        }
        bool RuntimeType::isReferenceType()
        {
            return !isValueType();
        }
        bool RuntimeType::isValueType()
        {
            return false;
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
