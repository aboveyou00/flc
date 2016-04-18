#pragma once
#include <vector>
#include "RuntimeType.h"
#include "ParameterInfo.h"
#include "MethodBody.h"

namespace flc
{
    namespace types
    {
        class MethodGroup;

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

            virtual void emitCall(emit::MethodBody *method) = 0;

        private:
            RuntimeType* _returnType;
            std::vector<ParameterInfo*> _params;
        };
    }
}
