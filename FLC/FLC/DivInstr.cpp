#include "stdafx.h"
#include "DivInstr.h"

namespace flc
{
    namespace emit
    {
        DivInstr::DivInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        DivInstr::~DivInstr()
        {
        }

        bool DivInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void DivInstr::stringify(std::stringstream *stream)
        {
            *stream << "div";
            if (!signedArithmetic) *stream << ".un";
        }
    }
}
