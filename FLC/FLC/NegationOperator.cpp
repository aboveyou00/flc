#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::negation = new UnaryOperator("-", "op_Negation");
    }
}
