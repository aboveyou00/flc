#pragma once
#include "INameInfo.h"

namespace flc
{
    namespace types
    {
        class IMemberInfo : public INameInfo
        {
        public:
            virtual ~IMemberInfo()
            {
            }
        };
    }
}
