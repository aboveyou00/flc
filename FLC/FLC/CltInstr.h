#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CltInstr : public Instr
        {
        public:
            CltInstr(bool useSigned = true);
            ~CltInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//FE 04   clt
//FE 05   clt.un
