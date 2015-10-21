#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class EndOfFileToken : public Token
        {
        public:
            EndOfFileToken(string sourceFile, int pos);
            ~EndOfFileToken();

            virtual string toString();
        };
    }
}
