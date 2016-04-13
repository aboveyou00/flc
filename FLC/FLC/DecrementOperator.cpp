#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::decrement = new UnaryOperator("--", "op_Decrement");
    }
}
