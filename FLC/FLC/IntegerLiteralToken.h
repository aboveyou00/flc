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
            IntegerLiteralToken(string sourceFile, int startPos, int length, int32_t value);
            ~IntegerLiteralToken();

            int32_t getValue();

            virtual string toString();

        private:
            int32_t _val;
        };
    }
}
