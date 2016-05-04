#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class StringLiteralToken : public Token
        {
        public:
            StringLiteralToken(std::string sourceFile, int startPos, int length, std::string value);
            ~StringLiteralToken();

            std::string getValue();

            bool isStringLiteral() override;
            bool isStringLiteral(std::string val) override;

            std::string toString() override;

        private:
            std::string _val;
        };
    }
}
