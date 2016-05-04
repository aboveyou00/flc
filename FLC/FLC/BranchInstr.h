#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class BranchTarget;

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
