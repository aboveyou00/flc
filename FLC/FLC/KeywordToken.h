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

            string getValue();

        private:
            string _val;
        };
    }
}
