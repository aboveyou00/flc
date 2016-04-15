#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::increment()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("++", "op_Increment");

                //auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
