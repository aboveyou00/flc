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
            BranchInstr(BranchTarget *target = nullptr);
            ~BranchInstr();

            BranchTarget *getBranchTarget();
            virtual bool isConditional();

            std::string opcode() override;
            void stringify(std::stringstream *stream) override;

        protected:
            virtual std::string base_opcode() = 0;

        private:
            BranchTarget *_target;
            bool isShort = false;
        };
    }
}
