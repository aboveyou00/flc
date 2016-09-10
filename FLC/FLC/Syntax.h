#pragma once
#include "stdafx.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        class Syntax
        {
        public:
            Syntax();
            ~Syntax();

            void reportError(std::string errorMessage);
            template <typename... TArgs>
            void reportError(std::string format, TArgs... args)
            {
                static const unsigned MAX_BUFFER_SIZE = 2048;
                static thread_local char buff[MAX_BUFFER_SIZE];
                sprintf_s(buff, format.c_str(), args...);
                reportError(std::string(buff));
            }

            virtual void stringify(stringstream* stream, int tabulation = 0) = 0;
            virtual string toString();

        protected:
            static void tabulate(stringstream* stream, int tabulation);
        };
    }
}
