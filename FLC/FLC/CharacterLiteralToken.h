#pragma once
#include <cstdint>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class CharacterLiteralToken : public Token
        {
        public:
            CharacterLiteralToken(std::string sourceFile, int startPos, int length, char16_t value);
            ~CharacterLiteralToken();

            char16_t getValue();

            bool isCharacterLiteral() override;
            bool isCharacterLiteral(char16_t val) override;

            virtual std::string toString();

        private:
            char16_t _val;
        };
    }
}
