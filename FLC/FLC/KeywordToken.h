#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class KeywordToken : public Token
        {
        public:
            KeywordToken(std::string sourceFile, int startPos, std::string value);
            ~KeywordToken();

            std::string getValue();

            bool isKeyword() override;
            bool isKeyword(std::string sym) override;

            std::string toString() override;

        private:
            std::string _val;
        };
    }
}
