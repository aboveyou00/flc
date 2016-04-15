#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::equality()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("==", "op_Equality");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];
            }

            return op;
        }
    }
}
