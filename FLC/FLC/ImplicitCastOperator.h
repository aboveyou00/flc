#pragma once
#include "CastOperator.h"

namespace flc
{
    namespace op
    {
        class ImplicitCastOperator : public CastOperator
        {
        public:
            ImplicitCastOperator();
            ~ImplicitCastOperator();

            types::MethodOverload *findOverload(types::RuntimeType *operand, types::RuntimeType *retType) override;

        private:
            types::MethodOverload *createMethodImpl(types::RuntimeType *operand, types::RuntimeType *retType, void(*impl)(emit::MethodBody*));
            types::MethodGroup cache;
        };
    }
}
