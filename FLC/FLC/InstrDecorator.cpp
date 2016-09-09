#include "stdafx.h"
#include "InstrDecorator.h"

namespace flc
{
    namespace emit
    {
        InstrDecorator::InstrDecorator(std::string name)
            : _name(name)
        {
        }
        InstrDecorator::~InstrDecorator()
        {
        }

        std::string InstrDecorator::getName()
        {
            return _name;
        }
        void InstrDecorator::setName(std::string name)
        {
            _name = name;
        }

        void InstrDecorator::stringify(std::stringstream *stream)
        {
            *stream << getName();
        }
        std::string InstrDecorator::toString()
        {
            return getName();
        }
    }
}
