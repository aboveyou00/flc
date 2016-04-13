#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::increment = new UnaryOperator("++", "op_Increment");
    }
}
