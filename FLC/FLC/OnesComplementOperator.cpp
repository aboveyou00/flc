#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::onesComplement = new UnaryOperator("~", "op_OnesComplement");
    }
}
