#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class ErrorToken : public Token
        {
        public:
            ErrorToken(std::string sourceFile, int startPos, int length, std::string error);
            ~ErrorToken();

            std::string getError();

            std::string toString() override;

        private:
            std::string _err;
        };
    }
}
