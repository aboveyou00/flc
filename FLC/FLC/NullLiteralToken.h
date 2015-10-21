#pragma once
#include "KeywordToken.h"

namespace flc
{
    namespace tokens
    {
        class NullLiteralToken : public KeywordToken
        {
        public:
            NullLiteralToken(string sourceFile, int startPos);
            ~NullLiteralToken();
        };
    }
}
