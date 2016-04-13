#pragma once
#include <string>
#include "NameType.h"

namespace flc
{
    namespace types
    {
        class INameInfo;

        class INameResolutionContext
        {
        public:
            virtual ~INameResolutionContext()
            {
            }

            virtual INameInfo* resolveName(std::string name, NameType nameType = NameType::Any) = 0;
        };
    }
}
