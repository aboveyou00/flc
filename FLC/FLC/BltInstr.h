#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BltInstr : public Instr
        {
        public:
            BltInstr(BranchTarget *target, bool useSigned = true);
            ~BltInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//3F <int32>   blt <target>
//32 <int8>    blt.s <target>
//44 <int32>   blt.un <target>
//37 <int8>    blt.un.s <target>