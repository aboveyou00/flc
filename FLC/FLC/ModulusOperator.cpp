#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::modulus = new BinaryOperator("%", "op_Modulus");
    }
}
