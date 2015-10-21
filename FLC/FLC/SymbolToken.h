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
            ~SymbolToken();

            string getSymbol();

            virtual string toString();

        private:
            string _sym;
        };
    }
}
