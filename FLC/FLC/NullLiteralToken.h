#pragma once
#include "KeywordToken.h"

namespace flc
{
    namespace tokens
    {
        class NullLiteralToken : public KeywordToken
        {
        public:
            NullLiteralToken(std::string sourceFile, int startPos);
            ~NullLiteralToken();

            bool isNullLiteral() override;
        };
    }
}
