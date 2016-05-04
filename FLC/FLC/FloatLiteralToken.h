#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class FloatLiteralToken : public Token
        {
        public:
            FloatLiteralToken(std::string sourceFile, int startPos, int length, float value);
            ~FloatLiteralToken();

            float getValue();

            bool isFloatLiteral() override;
            bool isFloatLiteral(float val) override;

            std::string toString() override;

        private:
            float _val;
        };
    }
}
