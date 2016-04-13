#pragma once
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        class RuntimeValueType : public RuntimeType
        {
        public:
            RuntimeValueType(std::string);
            ~RuntimeValueType();

            bool isReferenceType() override;
            bool isValueType() override;
        };
    }
}
