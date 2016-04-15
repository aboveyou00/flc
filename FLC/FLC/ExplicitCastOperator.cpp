#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::explicitCast()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("", "op_Explicit");

                auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
