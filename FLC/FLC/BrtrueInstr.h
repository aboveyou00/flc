#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BrtrueInstr : public BranchInstr
        {
        public:
            BrtrueInstr(BranchTarget *target);
            ~BrtrueInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//3A <int32>   brtrue <target>;     brinst <target>;
//2D <int8>    brtrue.s <target>;   brinst.s <target>;
