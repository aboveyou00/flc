#include "stdafx.h"
#include "BltInstr.h"
#include "BranchTarget.h"

namespace flc
{
    namespace emit
    {
        BltInstr::BltInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BltInstr::~BltInstr()
        {
        }

        bool BltInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void BltInstr::stringify(std::stringstream *stream)
        {
            *stream << "blt";
            if (!usesSignedArithmetic()) *stream << ".un";
            *stream << " ";
            getBranchTarget()->stringify(stream);
        }
    }
}
