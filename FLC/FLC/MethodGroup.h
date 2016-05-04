#pragma once
#include <vector>
#include "INameInfo.h"

namespace flc
{
    namespace types
    {
        class SpecialMethodOverload;
        class ParameterInfo;
        class MethodOverload;

        class MethodGroup : INameInfo
        {
        public:
            MethodGroup(std::string name);
            MethodGroup(std::string name, std::vector<MethodOverload*>* overloads);
            MethodGroup(std::string name, MethodOverload** overloads, int overloadCount);
            ~MethodGroup();

            std::string getName() override;
            NameType getNameType() override;

            int getOverloadCount();
            MethodOverload* getOverload(int idx);

            MethodOverload* findOverload(RuntimeType** parameters, int parameterCount);
            MethodOverload* findOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount);
            MethodOverload* findOverload(RuntimeType* returnType, ParameterInfo** parameters, int parameterCount);

            SpecialMethodOverload* addOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount);
            SpecialMethodOverload* addOverload(RuntimeType* returnType, ParameterInfo** parameters, int parameterCount);

        private:
            std::string _name;
            std::vector<MethodOverload*> _overloads;
        };
    }
}
