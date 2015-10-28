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
            IntegerLiteralToken(string sourceFile, int startPos, int length, uint32_t value);
            ~IntegerLiteralToken();

            uint32_t getValue();

            virtual bool isIntegerLiteral();
            virtual bool isIntegerLiteral(uint32_t val);

            virtual string toString();

        private:
            uint32_t _val;
        };
    }
}
