#pragma once
#include <vector>

namespace flc
{
    namespace emit
    {
        class Instr;

        class MethodBody
        {
        public:
            MethodBody();
            ~MethodBody();

            void emit(Instr *instr);
            void deleteInstructions();
            const std::vector<Instr*> *getInstructions();

            std::string toString();

        private:
            std::vector<Instr*> instructions;
        };
    }
}
