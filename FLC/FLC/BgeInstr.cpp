#include "stdafx.h"
#include "BgeInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BgeInstr::BgeInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BgeInstr::~BgeInstr()
        {
        }

        bool BgeInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void BgeInstr::stringify(std::stringstream *stream)
        {
            *stream << "bge";
            if (!usesSignedArithmetic()) *stream << ".un";
            *stream << " ";
            getBranchTarget()->stringify(stream);
        }
    }
}
