#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class SymbolToken : public Token
        {
        public:
            SymbolToken(string sourceFile, int startPos, string symbol);
            ~SymbolToken();

            string getSymbol();

            bool isSymbol() override;
            bool isSymbol(string sym) override;

            string toString() override;

        private:
            string _sym;
        };
    }
}
