#include "stdafx.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        BinaryOperator* const Operator::greaterThan = new BinaryOperator(">", "op_GreaterThan");
    }
}
