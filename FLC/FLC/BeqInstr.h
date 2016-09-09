#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BeqInstr : public BranchInstr
        {
        public:
            BeqInstr(BranchTarget *target = nullptr);
            ~BeqInstr();

        protected:
            std::string base_opcode() override;
        };
    }
}

//3B <int32>   beq <target>
//2E <int8>    beq.s <target>
