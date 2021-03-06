#pragma once
#include "CastOperator.h"
#include "MethodGroup.h"

namespace flc
{
    namespace emit
    {
        class MethodBody;
    }

    namespace op
    {
        class ImplicitCastOperator : public CastOperator
        {
        public:
            ImplicitCastOperator();
            ~ImplicitCastOperator();

            types::MethodOverload *findOverload(types::RuntimeType *operand, types::RuntimeType *retType) override;

        private:
            types::MethodOverload *createMethodImpl(types::RuntimeType *operand, types::RuntimeType *retType, std::function<void(emit::MethodBody*)> impl);
            types::MethodGroup cache;
        };
    }
}
