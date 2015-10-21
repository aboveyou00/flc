#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class IdentifierToken : public Token
        {
        public:
            IdentifierToken(string sourceFile, int startPos, int length, string value);

            string getValue();

            static Token* getToken(string sourceFile, int startPos, int length, string value);

        private:
            string _val;
        };
    }
}
