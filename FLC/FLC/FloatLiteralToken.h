#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class FloatLiteralToken : public Token
        {
        public:
            FloatLiteralToken(string sourceFile, int startPos, int length, float value);

            float getValue();

        private:
            float _val;
        };
    }
}
