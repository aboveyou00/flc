#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BneInstr : public BranchInstr
        {
        public:
            BneInstr(BranchTarget *target = nullptr);
            ~BneInstr();

        protected:
            std::string base_opcode() override;
        };
    }
}

//40 <int32>   bne <target>
//33 <int8>    bne.s <target>
