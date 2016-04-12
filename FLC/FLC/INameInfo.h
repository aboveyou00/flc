#pragma once
#include <string>
#include "NameType.h"

namespace flc
{
    namespace types
    {
        class RuntimeType;

        class INameInfo
        {
        public:
            virtual ~INameInfo() = 0;

            virtual std::string getName() = 0;
            virtual NameType getNameType() = 0;

            bool matchesSelector(std::string name, NameType nameType);

            virtual RuntimeType* getRuntimeType() = 0;
        };
    }
}
