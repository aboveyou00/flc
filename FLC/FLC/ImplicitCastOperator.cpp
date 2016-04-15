#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::implicitCast()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("", "op_Implicit");

                auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
