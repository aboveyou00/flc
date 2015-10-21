#include "stdafx.h"
#include "FloatLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        FloatLiteralToken::FloatLiteralToken(string sourceFile, int startPos, int length, float value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        FloatLiteralToken::~FloatLiteralToken()
        {
        }

        float FloatLiteralToken::getValue()
        {
            return _val;
        }
    }
}
