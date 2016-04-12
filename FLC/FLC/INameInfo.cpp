#pragma once
#include <string>
#include "INameInfo.h"

namespace flc
{
    namespace types
    {
        bool INameInfo::matchesSelector(std::string name, NameType nameType)
        {
            auto thisNameType = getNameType();
            return ((nameType & thisNameType) == thisNameType) && (getName().compare(name) == 0);
        }
    }
}
