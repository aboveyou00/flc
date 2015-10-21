#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class StringLiteralToken : public Token
        {
        public:
            StringLiteralToken(string sourceFile, int startPos, int length, string value);
            ~StringLiteralToken();

            string getValue();

            virtual string toString();

        private:
            string _val;
        };
    }
}