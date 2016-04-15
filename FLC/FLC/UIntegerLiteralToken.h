#pragma once
#include <cstdint>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class UIntegerLiteralToken : public Token
        {
        public:
            UIntegerLiteralToken(string sourceFile, int startPos, int length, uint32_t value);
            ~UIntegerLiteralToken();

            uint32_t getValue();

            bool isUIntegerLiteral() override;
            bool isUIntegerLiteral(uint32_t val) override;

            string toString() override;

        private:
            uint32_t _val;
        };
    }
}
