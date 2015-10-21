#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class CharacterLiteralToken : Token
        {
        public:
            CharacterLiteralToken(string sourceFile, int startPos, int length, char value);

            char getValue();

        private:
            char val;
        };
    }
}
