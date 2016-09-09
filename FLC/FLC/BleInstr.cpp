#include "stdafx.h"
#include "BleInstr.h"
#include "BranchTarget.h"

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

        std::string BleInstr::base_opcode()
        {
            if (signedArithmetic) return "ble"s;
            else return "ble.un"s;
        }
    }
}
