#pragma once
#include <string>
#include "MethodGroup.h"

namespace flc
{
    namespace op
    {
        class BinaryOperator;
        class UnaryOperator;

        class Operator
        {
        public:
            Operator(std::string opSymbol, std::string opMethodName);
            ~Operator();

            std::string getOperatorSymbol();
            std::string getOperatorMethodName();

            types::MethodGroup* getPredefinedOverloads();

        private:
            std::string _sym, _methodName;
            types::MethodGroup* _predefined = nullptr;

            //STATIC:
        public:
            static UnaryOperator *increment();
            static UnaryOperator *decrement();
            static UnaryOperator *negation();
            static UnaryOperator *unaryPlus();
            static UnaryOperator *logicalNot();
            static UnaryOperator *onesComplement();

            static UnaryOperator *implicitCast();
            static UnaryOperator *explicitCast();

            static BinaryOperator *multiplication();
            static BinaryOperator *division();
            static BinaryOperator *modulus();

            static BinaryOperator *addition();
            static BinaryOperator *subtraction();

            static BinaryOperator *leftShift();
            static BinaryOperator *rightShift();

            static BinaryOperator *greaterThan();
            static BinaryOperator *lessThan();
            static BinaryOperator *greaterThanOrEqual();
            static BinaryOperator *lessThanOrEqual();

            static BinaryOperator *equality();
            static BinaryOperator *inequality();

            static BinaryOperator *bitwiseAnd();

            static BinaryOperator *exclusiveOr();

            static BinaryOperator *bitwiseOr();
        };
    }
}
