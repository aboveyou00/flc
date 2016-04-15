#pragma once
#include "KeywordToken.h"

namespace flc
{
    namespace tokens
    {
        class BooleanLiteralToken : public KeywordToken
        {
        public:
            BooleanLiteralToken(string sourceFile, int startPos, bool value);
            ~BooleanLiteralToken();

            bool getValue();

            bool isBooleanLiteral() override;
            bool isBooleanLiteral(bool val) override;

        private:
            bool _val;
        };
    }
}
