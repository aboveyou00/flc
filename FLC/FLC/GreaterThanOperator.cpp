#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::greaterThan()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator(">", "op_GreaterThan");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];
            }

            return op;
        }
    }
}
