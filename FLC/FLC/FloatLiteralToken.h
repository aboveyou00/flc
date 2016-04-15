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

            bool isFloatLiteral() override;
            bool isFloatLiteral(float val) override;

            string toString() override;

        private:
            float _val;
        };
    }
}
