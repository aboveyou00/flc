#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::exclusiveOr = new BinaryOperator("^", "op_ExclusiveOr");
    }
}
