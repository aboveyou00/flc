#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class SymbolToken : public Token
        {
        public:
            SymbolToken(std::string sourceFile, int startPos, std::string symbol);
            ~SymbolToken();

            std::string getSymbol();

            bool isSymbol() override;
            bool isSymbol(std::string sym) override;

            std::string toString() override;

        private:
            std::string _sym;
        };
    }
}
