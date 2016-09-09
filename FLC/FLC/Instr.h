#pragma once
#include <string>
#include <sstream>
#include <vector>

namespace flc
{
    namespace emit
    {
        class InstrDecorator;

        class Instr
        {
        public:
            Instr();
            ~Instr();

            void addDecorator(InstrDecorator *decorator);
            const std::vector<InstrDecorator*> &getDecorators() const;

            virtual std::string opcode() = 0;
            virtual void stringify(std::stringstream *stream);
            virtual std::string toString();

        private:
            std::vector<InstrDecorator*> decorators;
        };
    }
}
