#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::unaryPlus = new UnaryOperator("+", "op_UnaryPlus");
    }
}
