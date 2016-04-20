#include "stdafx.h"
#include "CastOperator.h"

namespace flc
{
    namespace op
    {
        CastOperator *Operator::explicitCast()
        {
            static CastOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new CastOperator("op_Explicit");

                //auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }
    }
}
