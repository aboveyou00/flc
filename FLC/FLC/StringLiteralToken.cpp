#include "stdafx.h"
#include "StringLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        StringLiteralToken::StringLiteralToken(string sourceFile, int startPos, int length, string value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        StringLiteralToken::~StringLiteralToken()
        {
        }

        string StringLiteralToken::getValue()
        {
            return _val;
        }

        string StringLiteralToken::toString()
        {
            return _val;
        }
    }
}
