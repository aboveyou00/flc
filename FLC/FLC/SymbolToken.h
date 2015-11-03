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

            bool isSymbol();
            bool isSymbol(string sym);

            virtual string toString();

        private:
            string _sym;
        };
    }
}
