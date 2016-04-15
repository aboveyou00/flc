#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::bitwiseOr()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("|", "op_BitwiseOr");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];
            }

            return op;
        }
    }
}
