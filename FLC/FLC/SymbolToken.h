#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class SymbolToken : Token
        {
        public:
            SymbolToken(string sourceFile, int startPos, int length, string symbol);

            string getSymbol();

        private:
            float sym;
        };
    }
}
