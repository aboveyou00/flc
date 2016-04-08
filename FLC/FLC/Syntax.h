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

            virtual void stringify(stringstream* stream, int tabulation = 0) = 0;
            virtual string toString();

        protected:
            static void tabulate(stringstream* stream, int tabulation);
        };
    }
}
