#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BleInstr : public Instr
        {
        public:
            BleInstr(BranchTarget *target, bool useSigned = true);
            ~BleInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//3E <int32>   ble <target>
//31 <int8>    ble.s <target>
//43 <int32>   ble.un <target>
//36 <int8>    ble.un.s <target>
