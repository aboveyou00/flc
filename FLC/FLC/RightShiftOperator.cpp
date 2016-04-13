#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::rightShift = new BinaryOperator(">>", "op_RightShift");
    }
}
