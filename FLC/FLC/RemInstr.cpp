#include "stdafx.h"
#include "RemInstr.h"

namespace flc
{
    namespace emit
    {
        RemInstr::RemInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        RemInstr::~RemInstr()
        {
        }

        bool RemInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void RemInstr::stringify(std::stringstream *stream)
        {
            *stream << "rem";
            if (!signedArithmetic) *stream << ".un";
        }
    }
}
