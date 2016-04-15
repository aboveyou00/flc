#include "stdafx.h"
#include "UnaryOperator.h"

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
            }

            return op;
        }
    }
}
