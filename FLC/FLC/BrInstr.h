#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BrInstr : public BranchInstr
        {
        public:
            BrInstr(BranchTarget *target);
            ~BrInstr();

            bool isConditional() override;

            void stringify(std::stringstream *stream) override;
        };
    }
}

//38 <int32>   br <target>
//2B <int8>    br.s <target>
