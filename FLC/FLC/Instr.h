#pragma once
#include <string>
#include <sstream>

namespace flc
{
    namespace emit
    {
        class Instr
        {
        public:
            Instr();
            ~Instr();

            virtual void stringify(std::stringstream *stream) = 0;
            virtual std::string toString();
        };
    }
}
