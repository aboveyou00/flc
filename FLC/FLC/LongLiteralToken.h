#pragma once
#include <cstdint>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class LongLiteralToken : public Token
        {
        public:
            LongLiteralToken(string sourceFile, int startPos, int length, uint64_t value);
            ~LongLiteralToken();

            uint64_t getValue();

            bool isLongLiteral() override;
            bool isLongLiteral(uint64_t val) override;

            string toString() override;

        private:
            uint64_t _val;
        };
    }
}
