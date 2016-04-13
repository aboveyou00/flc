#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::inequality = new BinaryOperator("!=", "op_Inequality");
    }
}
