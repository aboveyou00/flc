#include "stdafx.h"
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        RuntimeType::RuntimeType(std::string name)
        {
            qualifiedName = name;
        }
        RuntimeType::~RuntimeType()
        {
        }

        std::string RuntimeType::getName()
        {
            auto idx = qualifiedName.find_last_of("::");
            if (idx == -1) return qualifiedName;
            return qualifiedName.substr(idx + 2);
        }
        std::string RuntimeType::getQualifiedName()
        {
            return qualifiedName;
        }

        INameInfo* RuntimeType::resolveName(std::string name)
        {
            return nullptr;
        }

        RuntimeType* const RuntimeType::void0 = new RuntimeType("System::Void");

        RuntimeType* const RuntimeType::bool8 = new RuntimeType("System::Boolean");

        RuntimeType* const RuntimeType::int8 = new RuntimeType("System::Int8");
        RuntimeType* const RuntimeType::int16 = new RuntimeType("System::Int16");
        RuntimeType* const RuntimeType::int32 = new RuntimeType("System::Int32");
        RuntimeType* const RuntimeType::int64 = new RuntimeType("System::Int64");

        RuntimeType* const RuntimeType::uint8 = new RuntimeType("System::UInt8");
        RuntimeType* const RuntimeType::uint16 = new RuntimeType("System::UInt16");
        RuntimeType* const RuntimeType::uint32 = new RuntimeType("System::UInt32");
        RuntimeType* const RuntimeType::uint64 = new RuntimeType("System::UInt64");

        RuntimeType* const RuntimeType::float32 = new RuntimeType("System::Float");
        RuntimeType* const RuntimeType::float64 = new RuntimeType("System::Double");

        RuntimeType* const RuntimeType::object = new RuntimeType("System::Object");
        RuntimeType* const RuntimeType::string = new RuntimeType("System::String");
        RuntimeType* const RuntimeType::char16 = new RuntimeType("System::Character");
    }
}
