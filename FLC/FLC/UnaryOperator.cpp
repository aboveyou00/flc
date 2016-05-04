#include "stdafx.h"
#include "UnaryOperator.h"
#include "MethodGroup.h"

namespace flc
{
    namespace op
    {
        UnaryOperator::UnaryOperator(std::string opSymbol, std::string opMethodName)
            : Operator(opSymbol, opMethodName)
        {
        }
        UnaryOperator::~UnaryOperator()
        {
        }

        types::MethodOverload* UnaryOperator::findOverload(types::RuntimeType *operand)
        {
            if (operand == nullptr) return nullptr;
            return getPredefinedOverloads()->findOverload(&operand, 1);
        }
    }
}
