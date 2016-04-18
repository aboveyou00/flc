#pragma once
#include "MethodOverload.h"

namespace flc
{
    namespace types
    {
        class SpecialMethodOverload : public MethodOverload
        {
        public:
            SpecialMethodOverload(RuntimeType* returnType, vector<ParameterInfo*>* params);
            SpecialMethodOverload(RuntimeType* returnType, ParameterInfo** params, int paramCount);
            ~SpecialMethodOverload();

            void emitCall(emit::MethodBody *method) override;
            void setEmitCallImplementation(void(*impl)(emit::MethodBody*));

        private:
            void(*_impl)(emit::MethodBody*) = nullptr;
        };
    }
}
