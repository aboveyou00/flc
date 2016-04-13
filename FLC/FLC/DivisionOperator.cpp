#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::division = new BinaryOperator("/", "op_Division");
    }
}
