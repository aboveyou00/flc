#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::equality = new BinaryOperator("==", "op_Equality");
    }
}
