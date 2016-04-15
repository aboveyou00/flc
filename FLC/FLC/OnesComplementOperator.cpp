#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::onesComplement()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("~", "op_OnesComplement");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *arg[1];

                __addOverload1(int32);
                __addOverload1(int64);
                __addOverload1(uint32);
                __addOverload1(uint64);
            }

            return op;
        }
    }
}
