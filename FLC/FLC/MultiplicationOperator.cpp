#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::multiplication()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("*", "op_Multiply");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32);
                __addOverload2(int64);
                __addOverload2(uint32);
                __addOverload2(uint64);

                __addOverload2(float32);
                __addOverload2(float64);
            }

            return op;
        }
    }
}
