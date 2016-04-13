#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::greaterThanOrEqual = new BinaryOperator(">=", "op_GreaterThanOrEqual");
    }
}
