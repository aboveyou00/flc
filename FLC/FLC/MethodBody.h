#pragma once
#include <vector>

namespace flc
{
    namespace emit
    {
        class Instr;
        class InstrDecorator;

        class MethodBody
        {
        public:
            MethodBody();
            ~MethodBody();

            void emit(Instr *instr);
            void emitDecorator(InstrDecorator *decorator);
            void finalize();

            void deleteInstructions();
            const std::vector<Instr*> *getInstructions();

            std::string toString();

        private:
            bool finalized;
            std::vector<Instr*> instructions;
            std::vector<InstrDecorator*> decorators;
        };
    }
}
