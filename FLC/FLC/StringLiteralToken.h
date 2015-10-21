#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class StringLiteralToken : Token
        {
        public:
            StringLiteralToken(string sourceFile, int startPos, int length, string value);

            string getValue();

        private:
            float val;
        };
    }
}
