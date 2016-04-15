#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::leftShift()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("<<", "op_LeftShift");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2_alt(int32, int32, int32);
                __addOverload2_alt(uint32, uint32, int32);
                __addOverload2_alt(int64, int64, int32);
                __addOverload2_alt(uint64, uint64, int32);

                __addOverload2_alt(bool8, float32, float32);
                __addOverload2_alt(bool8, float64, float64);
            }

            return op;
        }
    }
}
