#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class KeywordToken : public Token
        {
        public:
            KeywordToken(string sourceFile, int startPos, string value);
            ~KeywordToken();

            string getValue();

            virtual string toString();

        private:
            string _val;
        };
    }
}
