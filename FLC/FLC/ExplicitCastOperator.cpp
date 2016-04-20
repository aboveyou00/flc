#include "stdafx.h"
#include "ExplicitCastOperator.h"

namespace flc
{
    namespace op
    {
        CastOperator *Operator::explicitCast()
        {
            static ExplicitCastOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new ExplicitCastOperator();

                //auto overloads = op->getPredefinedOverloads();
            }

            return op;
        }

        ExplicitCastOperator::ExplicitCastOperator()
            : CastOperator("op_Explicit")
        {
        }
        ExplicitCastOperator::~ExplicitCastOperator()
        {
        }

        types::MethodOverload *ExplicitCastOperator::findOverload(types::RuntimeType *operand, types::RuntimeType *returnType)
        {
            return CastOperator::findOverload(operand, returnType);
        }
    }
}
