#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BrtrueInstr : public BranchInstr
        {
        public:
            BrtrueInstr(BranchTarget *target = nullptr);
            ~BrtrueInstr();

        protected:
            std::string base_opcode() override;
        };
    }
}

//3A <int32>   brtrue <target>;     brinst <target>;
//2D <int8>    brtrue.s <target>;   brinst.s <target>;
