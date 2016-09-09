#pragma once
#include <string>
#include <sstream>

namespace flc
{
    namespace emit
    {
        class InstrDecorator
        {
        public:
            InstrDecorator(std::string name = ""s);
            ~InstrDecorator();

            std::string getName();
            void setName(std::string name);

            virtual void stringify(std::stringstream *stream);
            std::string toString();

        private:
            std::string _name;
        };
    }
}
