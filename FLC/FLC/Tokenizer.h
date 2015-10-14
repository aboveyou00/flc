#pragma once
#include "stdafx.h"
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

            vector<Token> tokenize(istream *sourceFile);
        };
    }
}