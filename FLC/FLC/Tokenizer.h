#pragma once

#include <iostream>
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class Tokenizer
        {
        public:
            Tokenizer();
            ~Tokenizer();

            vector<Token> tokenize(istream sourceFile);
        };
    }
}