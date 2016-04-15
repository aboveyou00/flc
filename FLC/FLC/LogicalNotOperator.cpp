#include "stdafx.h"
#include "UnaryOperator.h"

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
            }

            return op;
        }
    }
}
