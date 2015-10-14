#include "stdafx.h"
#include "Tokenizer.h"
#include "Errors.h"

namespace flc
{
    namespace tokens
    {
        Tokenizer::Tokenizer()
        {
            
        }
        Tokenizer::~Tokenizer()
        {

        }

        vector<Token> Tokenizer::tokenize(istream *sourceFile)
        {
            reportError("Tokenizer.tokenizer not implemented", "", -1, -1);
            throw 20;
        }
    }
}
