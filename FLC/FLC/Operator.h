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
            types::MethodGroup* _predefined;

        public:
            static UnaryOperator *const increment, *const decrement, *const negation, *const unaryPlus, *const logicalNot, *const onesComplement;
            static UnaryOperator *const implicitCast, *const explicitCast;
            static BinaryOperator *const multiplication, *const division, *const modulus;
            static BinaryOperator *const addition, *const subtraction;
            static BinaryOperator *const leftShift, *const rightShift;
            static BinaryOperator *const greaterThan, *const lessThan, *const greaterThanOrEqual, *const lessThanOrEqual;
            static BinaryOperator *const equality, *const inequality;
            static BinaryOperator *const bitwiseAnd;
            static BinaryOperator *const exclusiveOr;
            static BinaryOperator *const bitwiseOr;
        };
    }
}
