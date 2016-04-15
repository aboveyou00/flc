#include "stdafx.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"

namespace flc
{
    namespace op
    {
        Operator::Operator(std::string opSymbol, std::string opMethodName)
            : _sym(opSymbol), _methodName(opMethodName)
        {
            _predefined = new types::MethodGroup(opMethodName);
        }
        Operator::~Operator()
        {
        }

        std::string Operator::getOperatorSymbol()
        {
            return _sym;
        }
        std::string Operator::getOperatorMethodName()
        {
            return _methodName;
        }

        types::MethodGroup* Operator::getPredefinedOverloads()
        {
            return _predefined;
        }
    }
}
