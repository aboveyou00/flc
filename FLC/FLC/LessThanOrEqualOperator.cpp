#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::lessThanOrEqual = new BinaryOperator("<=", "op_LessThanOrEqual");
    }
}
