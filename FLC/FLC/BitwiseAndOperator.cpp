#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::bitwiseAnd()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("&", "op_BitwiseAnd");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];
            }

            return op;
        }
    }
}
