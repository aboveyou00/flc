#pragma once
#include <vector>

namespace flc
{
    namespace emit
    {
        class MethodBody;
    }

    namespace types
    {
        class RuntimeType;
        class ParameterInfo;

        class MethodOverload
        {
        public:
            MethodOverload(RuntimeType* returnType, vector<ParameterInfo*>* params);
            MethodOverload(RuntimeType* returnType, ParameterInfo** params, int paramCount);
            ~MethodOverload();

            RuntimeType* getReturnType();
            
            int getParameterCount();
            ParameterInfo* getParameterInfo(int idx);

            bool isMatchForParameters(RuntimeType** paramTypes, int paramCount);
            bool isBetterMatch(RuntimeType **parameters, int parameterCount, MethodOverload *other);

            virtual void emitCall(emit::MethodBody *method) = 0;

        private:
            RuntimeType* _returnType;
            std::vector<ParameterInfo*> _params;
        };
    }
}
