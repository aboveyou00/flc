#include "stdafx.h"
#include "SubInstr.h"

namespace flc
{
    namespace emit
    {
        SubInstr::SubInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        SubInstr::~SubInstr()
        {
        }

        bool SubInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool SubInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void SubInstr::stringify(std::stringstream *stream)
        {
            *stream << "sub";
            if (checkOverflow)
            {
                *stream << ".ovf";
                if (!signedArithmetic) *stream << ".un";
            }
        }
    }
}
