#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::leftShift = new BinaryOperator("<<", "op_LeftShift");
    }
}
