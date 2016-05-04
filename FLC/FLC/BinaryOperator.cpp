#include "stdafx.h"
#include "BinaryOperator.h"
#include "MethodGroup.h"

namespace flc
{
    namespace op
    {
        BinaryOperator::BinaryOperator(std::string opSymbol, std::string opMethodName)
            : Operator(opSymbol, opMethodName)
        {
        }
        BinaryOperator::~BinaryOperator()
        {
        }

        types::MethodOverload* BinaryOperator::findOverload(types::RuntimeType *left, types::RuntimeType *right)
        {
            types::RuntimeType* params[2] = { left, right };
            if (params[0] == nullptr || params[1] == nullptr) return nullptr;
            return getPredefinedOverloads()->findOverload(params, 2);
        }
    }
}
