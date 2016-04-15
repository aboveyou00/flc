#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class ErrorToken : public Token
        {
        public:
            ErrorToken(string sourceFile, int startPos, int length, string error);
            ~ErrorToken();

            string getError();

            string toString() override;

        private:
            string _err;
        };
    }
}
