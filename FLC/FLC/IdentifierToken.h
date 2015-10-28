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
            ~IdentifierToken();

            string getValue();

            bool isIdentifier();
            bool isIdentifier(string val);

            virtual string toString();

            static Token* getToken(string sourceFile, int startPos, int length, string value);

        private:
            string _val;
        };
    }
}
