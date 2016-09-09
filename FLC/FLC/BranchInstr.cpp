#include "stdafx.h"
#include "BranchInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BranchInstr::BranchInstr(BranchTarget *target)
            : _target(target != nullptr ? target : new BranchTarget()),
              isShort(false)
        {
        }
        BranchInstr::~BranchInstr()
        {
        }

        BranchTarget *BranchInstr::getBranchTarget()
        {
            return _target;
        }
        bool BranchInstr::isConditional()
        {
            return true;
        }

        std::string BranchInstr::opcode()
        {
            if (isShort) return base_opcode() + ".s";
            else return base_opcode();
        }
        void BranchInstr::stringify(std::stringstream *stream)
        {
            Instr::stringify(stream);
            *stream << " ";
            getBranchTarget()->stringify(stream);
        }
    }
}
