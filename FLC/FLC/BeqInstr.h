#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BeqInstr : public BranchInstr
        {
        public:
            BeqInstr(BranchTarget *target);
            ~BeqInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//3B <int32>   beq <target>
//2E <int8>    beq.s <target>
