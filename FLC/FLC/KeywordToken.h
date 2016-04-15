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

            bool isKeyword() override;
            bool isKeyword(string sym) override;

            string toString() override;

        private:
            string _val;
        };
    }
}
