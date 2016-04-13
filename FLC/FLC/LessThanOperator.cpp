#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::lessThan = new BinaryOperator("<", "op_LessThan");
    }
}
