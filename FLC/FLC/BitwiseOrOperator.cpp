#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::bitwiseOr()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("|", "op_BitwiseOr");

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
