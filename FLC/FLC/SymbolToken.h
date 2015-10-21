#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class SymbolToken : public Token
        {
        public:
            SymbolToken(string sourceFile, int startPos, int length, string symbol);

            string getSymbol();

        private:
            string _sym;
        };
    }
}
