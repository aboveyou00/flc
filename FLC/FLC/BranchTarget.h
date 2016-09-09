#pragma once
#include "InstrDecorator.h"

namespace flc
{
    namespace emit
    {
        class BranchTarget : public InstrDecorator
        {
        public:
            BranchTarget(std::string name = ""s);
            ~BranchTarget();
        };
    }
}
