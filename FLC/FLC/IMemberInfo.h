#pragma once
#include "INameInfo.h"

namespace flc
{
    namespace types
    {
        class RuntimeType;

        class IMemberInfo : public INameInfo
        {
        public:
            virtual ~IMemberInfo()
            {
            }
        };
    }
}
