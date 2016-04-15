#pragma once
#include <cstdint>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class ULongLiteralToken : public Token
        {
        public:
            ULongLiteralToken(string sourceFile, int startPos, int length, uint64_t value);
            ~ULongLiteralToken();

            uint64_t getValue();

            bool isULongLiteral() override;
            bool isULongLiteral(uint64_t val) override;

            string toString() override;

        private:
            uint64_t _val;
        };
    }
}
