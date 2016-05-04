#pragma once
#include <string>

namespace flc
{
    namespace types
    {
        class RuntimeType;
        class ParameterInfo;

        class ParameterInfo
        {
        public:
            ParameterInfo(RuntimeType* type);
            ParameterInfo(RuntimeType* type, std::string name);
            ParameterInfo(RuntimeType* type, std::string name, std::string desc);
            ~ParameterInfo();

            RuntimeType* getType();

            std::string getName();
            std::string getDescription();

            bool isSameAs(ParameterInfo* other);
            static bool areSameType(ParameterInfo* one, ParameterInfo* two);

        private:
            RuntimeType* _type;
            std::string _name, _desc;
        };
    }
}
