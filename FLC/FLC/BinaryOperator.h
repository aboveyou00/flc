#pragma once
#include "Operator.h"

namespace flc
{
    namespace op
    {
        class BinaryOperator : public Operator
        {
        public:
            BinaryOperator(std::string opSymbol, std::string opMethodName);
            ~BinaryOperator();

            virtual types::MethodOverload* findOverload(types::RuntimeType* left, types::RuntimeType* right);
        };
    }
}
