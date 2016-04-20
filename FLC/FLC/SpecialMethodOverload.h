#pragma once
#include <functional>
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
            void setEmitCallImplementation(std::function<void(emit::MethodBody*)> impl);

        private:
            std::function<void(emit::MethodBody*)> _impl = nullptr;
        };
    }
}
