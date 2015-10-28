#include "stdafx.h"
#include "IntegerLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        IntegerLiteralToken::IntegerLiteralToken(string sourceFile, int startPos, int length, uint32_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        IntegerLiteralToken::~IntegerLiteralToken()
        {
        }

        uint32_t IntegerLiteralToken::getValue()
        {
            return _val;
        }

        bool IntegerLiteralToken::isIntegerLiteral()
        {
            return true;
        }
        bool IntegerLiteralToken::isIntegerLiteral(uint32_t val)
        {
            return _val == val;
        }

        string IntegerLiteralToken::toString()
        {
            stringstream stream;
            stream << _val;
            return stream.str();
        }
    }
}
