#pragma once
#include <string>
#include <vector>
#include "INameResolutionContext.h"
#include "IMemberInfo.h"

namespace flc
{
    namespace types
    {
        class RuntimeType : public INameResolutionContext
        {
        public:
            RuntimeType(std::string name);
            ~RuntimeType();

            IMemberInfo* resolveName(std::string name, NameType nameType) override;

            std::string getName();
            std::string getQualifiedName();

            bool isSameAs(RuntimeType* other);
            static bool areSameType(RuntimeType* one, RuntimeType* two);

        private:
            std::string _qualifiedName;
            std::vector<IMemberInfo*>* _members;

        public:
            //Placeholder types, until we have a system in place to actually load the types from the CLR
            static RuntimeType *const void0;
            static RuntimeType *const bool8;
            static RuntimeType *const int8, *const int16, *const int32, *const int64;
            static RuntimeType *const uint8, *const uint16, *const uint32, *const uint64;
            static RuntimeType *const float32, *const float64;
            static RuntimeType *const object, *const string, *const char16;
        };
    }
}
