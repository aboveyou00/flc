#include "stdafx.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "MethodGroup.h"

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
            if (_predefined != nullptr) delete _predefined;
            _predefined = nullptr;
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
