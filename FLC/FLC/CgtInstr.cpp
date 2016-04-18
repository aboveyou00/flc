#include "stdafx.h"
#include "CgtInstr.h"

namespace flc
{
    namespace emit
    {
        CgtInstr::CgtInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        CgtInstr::~CgtInstr()
        {
        }

        bool CgtInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void CgtInstr::stringify(std::stringstream *stream)
        {
            *stream << "cgt";
            if (!signedArithmetic) *stream << ".un";
        }
    }
}
