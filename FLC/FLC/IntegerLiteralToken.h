#pragma once
#include <cstdint>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class IntegerLiteralToken : public Token
        {
        public:
            IntegerLiteralToken(std::string sourceFile, int startPos, int length, uint32_t value);
            ~IntegerLiteralToken();

            uint32_t getValue();

            bool isIntegerLiteral() override;
            bool isIntegerLiteral(uint32_t val) override;

            std::string toString() override;

        private:
            uint32_t _val;
        };
    }
}
