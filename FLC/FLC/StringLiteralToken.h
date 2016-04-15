#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class StringLiteralToken : public Token
        {
        public:
            StringLiteralToken(string sourceFile, int startPos, int length, string value);
            ~StringLiteralToken();

            string getValue();

            bool isStringLiteral() override;
            bool isStringLiteral(string val) override;

            string toString() override;

        private:
            string _val;
        };
    }
}
