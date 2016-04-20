#include "stdafx.h"
#include "CastOperator.h"

namespace flc
{
    namespace op
    {
        CastOperator::CastOperator(std::string opMethodName)
            : Operator("", opMethodName)
        {
        }
        CastOperator::~CastOperator()
        {
        }

        types::MethodOverload *CastOperator::findOverload(types::RuntimeType *operand, types::RuntimeType *retType)
        {
            types::RuntimeType* params[1] = { operand };
            if (params[0] == nullptr) return nullptr;
            return getPredefinedOverloads()->findOverload(retType, params, 1);
        }
    }
}
