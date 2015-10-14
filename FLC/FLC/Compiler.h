#pragma once
#include "stdafx.h"

namespace flc
{
    class Compiler
    {
    public:
        Compiler();
        ~Compiler();

        bool tryAddSourceFile(string path);

        bool tryCompile();
    };
}
