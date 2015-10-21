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

            bool getValue();

        private:
            bool _val;
        };
    }
}
