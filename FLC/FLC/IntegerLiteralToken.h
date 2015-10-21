#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class IntegerLiteralToken : public Token
        {
        public:
            IntegerLiteralToken(string sourceFile, int startPos, int length, int value);

            int getValue();

        private:
            int _val;
        };
    }
}
