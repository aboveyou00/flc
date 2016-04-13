#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::explicitCast = new UnaryOperator("", "op_Explicit");
    }
}
