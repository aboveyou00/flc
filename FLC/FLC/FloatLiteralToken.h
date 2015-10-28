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
            ~FloatLiteralToken();

            float getValue();

            virtual bool isFloatLiteral();
            virtual bool isFloatLiteral(float val);

            virtual string toString();

        private:
            float _val;
        };
    }
}
