#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::exclusiveOr()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("^", "op_ExclusiveOr");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32);
                __addOverload2(int64);
                __addOverload2(uint32);
                __addOverload2(uint64);

                __addOverload2(bool8);
            }

            return op;
        }
    }
}
