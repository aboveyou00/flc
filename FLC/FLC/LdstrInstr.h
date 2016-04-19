#pragma once
#include <string>
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class LdstrInstr : public Instr
        {
        public:
            LdstrInstr(std::string value);
            ~LdstrInstr();

            std::string getValue();

            void stringify(std::stringstream *stream) override;

        private:
            std::string value;
        };
    }
}

//72 <T>   ldstr <string>
