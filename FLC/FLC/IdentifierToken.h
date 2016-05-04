#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class IdentifierToken : public Token
        {
        public:
            IdentifierToken(std::string sourceFile, int startPos, int length, std::string value);
            ~IdentifierToken();

            std::string getValue();

            bool isIdentifier() override;
            bool isIdentifier(std::string val) override;

            std::string toString() override;

            static Token* getToken(std::string sourceFile, int startPos, int length, std::string value);

        private:
            std::string _val;
        };
    }
}
