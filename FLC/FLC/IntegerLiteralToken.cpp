#include "stdafx.h"
#include "IntegerLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        IntegerLiteralToken::IntegerLiteralToken(string sourceFile, int startPos, int length, int32_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        IntegerLiteralToken::~IntegerLiteralToken()
        {
        }

        int32_t IntegerLiteralToken::getValue()
        {
            return _val;
        }

        string IntegerLiteralToken::toString()
        {
            stringstream stream;
            stream << _val;
            return stream.str();
        }
    }
}
