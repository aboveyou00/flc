#include "stdafx.h"
#include "CharacterLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        CharacterLiteralToken::CharacterLiteralToken(string sourceFile, int startPos, int length, char value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        CharacterLiteralToken::~CharacterLiteralToken()
        {
        }

        char CharacterLiteralToken::getValue()
        {
            return _val;
        }
    }
}
