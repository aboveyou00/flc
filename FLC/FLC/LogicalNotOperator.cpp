#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::logicalNot = new UnaryOperator("!", "op_LogicalNot");
    }
}
