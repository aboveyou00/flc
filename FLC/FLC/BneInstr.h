#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BneInstr : public BranchInstr
        {
        public:
            BneInstr(BranchTarget *target);
            ~BneInstr();

            void stringify(std::stringstream *stream) override;
        };
    }
}

//40 <int32>   bne <target>
//33 <int8>    bne.s <target>
