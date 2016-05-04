#include "stdafx.h"
#include "ParameterInfo.h"
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        ParameterInfo::ParameterInfo(RuntimeType* type)
            : ParameterInfo(type, "", "")
        {
        }
        ParameterInfo::ParameterInfo(RuntimeType* type, std::string name)
            : ParameterInfo(type, name, "")
        {
        }
        ParameterInfo::ParameterInfo(RuntimeType* type, std::string name, std::string desc)
            : _type(type), _name(name), _desc(desc)
        {
        }
        ParameterInfo::~ParameterInfo()
        {
        }

        RuntimeType* ParameterInfo::getType()
        {
            return _type;
        }

        std::string ParameterInfo::getName()
        {
            return _name;
        }
        std::string ParameterInfo::getDescription()
        {
            return _desc;
        }

        bool ParameterInfo::isSameAs(ParameterInfo* other)
        {
            return ParameterInfo::areSameType(this, other);
        }
        bool ParameterInfo::areSameType(ParameterInfo* one, ParameterInfo* two)
        {
            if (one == nullptr || two == nullptr) return false;
            if (one == two) return true;
            if (one->getName().compare(two->getName()) != 0) return false;
            if (one->getDescription().compare(two->getDescription()) != 0) return false;
            if (!one->getType()->isSameAs(two->getType())) return false;
            return true;
        }
    }
}
