#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::unaryPlus()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("+", "op_UnaryPlus");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *arg[1];

                __addOverload1(int32)->setEmitCallImplementation([](emit::MethodBody*) { });
                __addOverload1(int64)->setEmitCallImplementation([](emit::MethodBody*) { });
                __addOverload1(uint32)->setEmitCallImplementation([](emit::MethodBody*) { });
                __addOverload1(uint64)->setEmitCallImplementation([](emit::MethodBody*) { });

                __addOverload1(float32)->setEmitCallImplementation([](emit::MethodBody*) { });
                __addOverload1(float64)->setEmitCallImplementation([](emit::MethodBody*) { });
            }

            return op;
        }
    }
}
