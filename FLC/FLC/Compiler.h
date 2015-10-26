#pragma once
#include <string>
#include <istream>
#include <vector>
#include "Token.h"

namespace flc
{
    using namespace std;

    class Compiler
    {
    public:
        Compiler();
        ~Compiler();

        bool tryAddSource(string source, string path = "Unknown Code Source");
        bool tryAddSource(istream *source, string path = "Unknown Code Source");
        bool tryAddSourceFile(string path);

        bool tryCompile();

    private:
        vector<vector<tokens::Token*>*> sourceFiles;
        bool assertValidTokens();
    };
}
