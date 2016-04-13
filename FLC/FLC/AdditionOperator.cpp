#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::addition = new BinaryOperator("+", "op_Addition");
    }
}
