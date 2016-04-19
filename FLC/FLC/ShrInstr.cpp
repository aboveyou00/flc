#include "stdafx.h"
#include "ShrInstr.h"

namespace flc
{
    namespace emit
    {
        ShrInstr::ShrInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        ShrInstr::~ShrInstr()
        {
        }

        bool ShrInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void ShrInstr::stringify(std::stringstream *stream)
        {
            *stream << "shr";
            if (!signedArithmetic) *stream << ".un";
        }
    }
}
