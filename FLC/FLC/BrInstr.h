#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BrInstr : public BranchInstr
        {
        public:
            BrInstr(BranchTarget *target = nullptr);
            ~BrInstr();

            bool isConditional() override;

        protected:
            std::string base_opcode() override;
        };
    }
}

//38 <int32>   br <target>
//2B <int8>    br.s <target>
