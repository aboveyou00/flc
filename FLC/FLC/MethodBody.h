#pragma once
#include "Instr.h"

namespace flc
{
    namespace emit
    {
        class MethodBody
        {
        public:
            MethodBody();
            ~MethodBody();

            void emit(Instr *instr);

            std::string toString();

        private:
            std::vector<Instr*> instructions;
        };
    }
}
