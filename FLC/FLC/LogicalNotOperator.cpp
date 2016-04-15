#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::logicalNot()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("!", "op_LogicalNot");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType **arg;

                __addOverload1(int32);
            }

            return op;
        }
    }
}
