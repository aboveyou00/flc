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

            virtual bool isReferenceType();
            virtual bool isValueType();

            bool isSameAs(RuntimeType* other);
            static bool areSameType(RuntimeType* one, RuntimeType* two);

        private:
            std::string _qualifiedName;
            std::vector<IMemberInfo*> _members;

        public:
            //Placeholder types, until we have a system in place to actually load the types from the CLR
            static RuntimeType *void0();

            static RuntimeType *bool8();

            static RuntimeType *int8();
            static RuntimeType *int16();
            static RuntimeType *int32();
            static RuntimeType *int64();

            static RuntimeType *uint8();
            static RuntimeType *uint16();
            static RuntimeType *uint32();
            static RuntimeType *uint64();

            static RuntimeType *float32();
            static RuntimeType *float64();

            static RuntimeType *object();
            static RuntimeType *string();
            static RuntimeType *char16();
            static RuntimeType *nullLiteral();
        };
    }
}
