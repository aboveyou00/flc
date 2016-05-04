#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BgeInstr : public BranchInstr
        {
        public:
            BgeInstr(BranchTarget *target, bool useSigned = true);
            ~BgeInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//3C <int32>   bge <target>
//2F <int8>    bge.s <target>
//41 <int32>   bge.un <target>
//34 <int8>    bge.un.s <target>
