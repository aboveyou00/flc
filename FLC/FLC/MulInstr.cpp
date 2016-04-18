#include "stdafx.h"
#include "MulInstr.h"

namespace flc
{
    namespace emit
    {
        MulInstr::MulInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        MulInstr::~MulInstr()
        {
        }

        bool MulInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool MulInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void MulInstr::stringify(std::stringstream *stream)
        {
            *stream << "mul";
            if (checkOverflow)
            {
                *stream << ".ovf";
                if (!signedArithmetic) *stream << ".un";
            }
        }
    }
}
