#pragma once
#include <string>
#include "INameResolutionContext.h"

namespace flc
{
    namespace types
    {
        class INameInfo;

        class RuntimeType : public INameResolutionContext
        {
        public:
            RuntimeType(std::string name);
            ~RuntimeType();

            INameInfo* resolveName(std::string name, NameType nameType);

            std::string getName();
            std::string getQualifiedName();

        private:
            std::string qualifiedName;

        public:
            //Placeholder types, until we have a system in place to actually load the types from the CLR
            static RuntimeType* const void0;

            static RuntimeType* const bool8;

            static RuntimeType* const int8;
            static RuntimeType* const int16;
            static RuntimeType* const int32;
            static RuntimeType* const int64;

            static RuntimeType* const uint8;
            static RuntimeType* const uint16;
            static RuntimeType* const uint32;
            static RuntimeType* const uint64;

            static RuntimeType* const float32;
            static RuntimeType* const float64;

            static RuntimeType* const object;
            static RuntimeType* const string;
            static RuntimeType* const char16;
        };
    }
}
