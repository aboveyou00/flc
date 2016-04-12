#pragma once
#include <string>

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

            virtual RuntimeType* getRuntimeType() = 0;
        };
    }
}
