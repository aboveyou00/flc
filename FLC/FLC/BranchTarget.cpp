#include "stdafx.h"
#include "BranchTarget.h"
#include <iostream>

namespace flc
{
    namespace emit
    {
        BranchTarget::BranchTarget(std::string name)
            : _name(name)
        {
        }
        BranchTarget::~BranchTarget()
        {
        }

        std::string BranchTarget::getName()
        {
            return _name;
        }

        void BranchTarget::stringify(std::stringstream *stream)
        {
            *stream << getName();
        }
        std::string BranchTarget::toString()
        {
            return getName();
        }
    }
}
