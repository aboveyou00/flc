#include "stdafx.h"
#include "AddInstr.h"

namespace flc
{
    namespace emit
    {
        AddInstr::AddInstr(bool checkOverflow, bool useSigned)
            : checkOverflow(checkOverflow), signedArithmetic(useSigned)
        {
        }
        AddInstr::~AddInstr()
        {
        }

        bool AddInstr::checksOverflow()
        {
            return checkOverflow;
        }
        bool AddInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void AddInstr::stringify(std::stringstream *stream)
        {
            *stream << "add";
            if (checkOverflow)
            {
                *stream << ".ovf";
                if (!signedArithmetic) *stream << ".un";
            }
        }
    }
}
