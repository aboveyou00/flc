#include "stdafx.h"
#include "BleInstr.h"

namespace flc
{
    namespace emit
    {
        BleInstr::BleInstr(BranchTarget *target, bool useSigned)
            : BranchInstr(target), signedArithmetic(useSigned)
        {
        }
        BleInstr::~BleInstr()
        {
        }

        bool BleInstr::usesSignedArithmetic()
        {
            return signedArithmetic;
        }

        void BleInstr::stringify(std::stringstream *stream)
        {
            *stream << "ble";
            if (!usesSignedArithmetic()) *stream << ".un";
            *stream << " ";
            getBranchTarget()->stringify(stream);
        }
    }
}
