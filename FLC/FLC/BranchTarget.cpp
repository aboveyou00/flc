#include "stdafx.h"
#include "BranchTarget.h"
#include <iostream>

namespace flc
{
    namespace emit
    {
        BranchTarget::BranchTarget(std::string name)
            : InstrDecorator(name)
        {
        }
        BranchTarget::~BranchTarget()
        {
        }
    }
}
