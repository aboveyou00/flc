#pragma once
#include <string>
#include <istream>
#include <vector>

namespace flc
{
    namespace tokens
    {
        class Token;
    }

    class Compiler
    {
    public:
        Compiler();
        ~Compiler();

        bool tryAddSource(std::string source, std::string path = "Unknown Code Source");
        bool tryAddSource(std::istream *source, std::string path = "Unknown Code Source");
        bool tryAddSourceFile(std::string path);

        bool tryCompile();

    private:
        std::vector<std::vector<tokens::Token*>*> sourceFiles;
        bool assertValidTokens();
    };
}
