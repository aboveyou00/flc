#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::negation()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("-", "op_Negation");

                auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
