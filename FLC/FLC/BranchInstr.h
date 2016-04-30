#pragma once
#include "Instr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        class BranchInstr : public Instr
        {
        public:
            BranchInstr(BranchTarget *target);
            ~BranchInstr();

            BranchTarget *getBranchTarget();
            virtual bool isConditional() = 0;

        private:
            BranchTarget *_target;
        };
    }
}
