#pragma once
#include "stdafx.h"

namespace flc
{
    namespace syntax
    {
        class Syntax
        {
        public:
            Syntax();
            ~Syntax();

            virtual string toString() = 0;
        };
    }
}
