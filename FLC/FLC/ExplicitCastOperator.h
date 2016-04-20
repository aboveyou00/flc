#pragma once
#include "CastOperator.h"

namespace flc
{
    namespace op
    {
        class ExplicitCastOperator : public CastOperator
        {
        public:
            ExplicitCastOperator();
            ~ExplicitCastOperator();

            types::MethodOverload *findOverload(types::RuntimeType *operand, types::RuntimeType *retType) override;
        };
    }
}
