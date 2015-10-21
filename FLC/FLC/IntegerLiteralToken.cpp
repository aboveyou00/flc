#include "stdafx.h"
#include "IntegerLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        IntegerLiteralToken::IntegerLiteralToken(string sourceFile, int startPos, int length, int value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        IntegerLiteralToken::~IntegerLiteralToken()
        {
        }

        int IntegerLiteralToken::getValue()
        {
            return _val;
        }
    }
}
