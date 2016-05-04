#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class EndOfFileToken : public Token
        {
        public:
            EndOfFileToken(std::string sourceFile, int pos);
            ~EndOfFileToken();

            bool isEndOfFile() override;

            std::string toString() override;
        };
    }
}
