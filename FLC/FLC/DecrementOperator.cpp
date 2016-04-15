#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::decrement()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("--", "op_Decrement");

                //auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
