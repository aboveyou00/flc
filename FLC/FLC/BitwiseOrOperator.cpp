#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::bitwiseOr = new BinaryOperator("|", "op_BitwiseOr");
    }
}
