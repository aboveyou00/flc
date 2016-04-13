#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::bitwiseAnd = new BinaryOperator("&", "op_BitwiseAnd");
    }
}
