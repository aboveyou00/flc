#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class CgtInstr : public Instr
        {
        public:
            CgtInstr(bool useSigned = true);
            ~CgtInstr();

            bool usesSignedArithmetic();

            void stringify(std::stringstream *stream) override;

        private:
            bool signedArithmetic;
        };
    }
}

//FE 02   cgt
//FE 03   cgt.un
