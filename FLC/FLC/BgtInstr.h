#pragma once
#include "BranchInstr.h"

namespace flc
{
    namespace emit
    {
        class BgtInstr : public BranchInstr
        {
        public:
            BgtInstr(BranchTarget *target, bool useSigned = true);
            ~BgtInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//3D <int32>   bgt <target>
//30 <int8>    bgt.s <target>
//42 <int32>   bgt.un <target>
//35 <int8>    bgt.un.s <target>
