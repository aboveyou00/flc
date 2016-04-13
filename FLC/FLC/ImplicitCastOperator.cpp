#include "stdafx.h"
#include "UnaryOperator.h"

namespace flc
{
    namespace op
    {
        UnaryOperator* const Operator::implicitCast = new UnaryOperator("", "op_Implicit");
    }
}
