#include "stdafx.h"
#include "BgtInstr.h"

namespace flc
{
    namespace emit
    {
        BgtInstr::BgtInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BgtInstr::~BgtInstr()
        {
        }

        bool BgtInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void BgtInstr::stringify(std::stringstream *stream)
        {
            *stream << "bgt";
            if (!usesSignedArithmetic()) *stream << ".un";
            *stream << " ";
            getBranchTarget()->stringify(stream);
        }
    }
}
