#pragma once
#include <string>
#include "Operator.h"

namespace flc
{
    namespace op
    {
        class UnaryOperator : public Operator
        {
        public:
            UnaryOperator(std::string opSymbol, std::string opMethodName);
            ~UnaryOperator();

            types::MethodOverload* findOverload(types::RuntimeType* operand);
        };
    }
}
