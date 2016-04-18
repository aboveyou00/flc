#include "stdafx.h"
#include "CltInstr.h"

namespace flc
{
    namespace emit
    {
        CltInstr::CltInstr(bool useSigned)
            : signedArithmetic(useSigned)
        {
        }
        CltInstr::~CltInstr()
        {
        }

        bool CltInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void CltInstr::stringify(std::stringstream *stream)
        {
            *stream << "clt";
            if (!signedArithmetic) *stream << ".un";
        }
    }
}
