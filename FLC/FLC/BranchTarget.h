#pragma once
#include <string>
#include <sstream>

namespace flc
{
    namespace emit
    {
        class BranchTarget
        {
        public:
            BranchTarget(std::string name = "");
            ~BranchTarget();

            std::string getName();

            void stringify(std::stringstream *stream);
            std::string toString();

        private:
            std::string _name;
        };
    }
}
