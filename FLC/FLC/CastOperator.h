#pragma once
#include "Operator.h"

namespace flc
{
    namespace op
    {
        class CastOperator : public Operator
        {
        public:
            CastOperator(std::string methodName);
            ~CastOperator();

            virtual types::MethodOverload *findOverload(types::RuntimeType *operand, types::RuntimeType *retType);
        };
    }
}
