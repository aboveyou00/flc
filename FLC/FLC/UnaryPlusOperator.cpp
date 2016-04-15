#include "stdafx.h"
#include "UnaryOperator.h"

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
            }

            return op;
        }
    }
}
