#pragma once
#include <string>

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

            virtual INameInfo* resolveName(std::string name) = 0;
        };
    }
}
