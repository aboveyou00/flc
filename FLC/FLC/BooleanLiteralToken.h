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

            virtual bool isBooleanLiteral();
            virtual bool isBooleanLiteral(bool val);

        private:
            bool _val;
        };
    }
}
