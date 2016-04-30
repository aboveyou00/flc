#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BrfalseInstr : public BranchInstr
        {
        public:
            BrfalseInstr(BranchTarget *target);
            ~BrfalseInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//39 <int32>   brfalse <target>;     brnull <target>;     brzero <target>
//2C <int8>    brfalse.s <target>;   brnull.s <target>;   brzero.s <target>
