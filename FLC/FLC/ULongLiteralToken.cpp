#include "stdafx.h"
#include "ULongLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        ULongLiteralToken::ULongLiteralToken(string sourceFile, int startPos, int length, uint64_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        ULongLiteralToken::~ULongLiteralToken()
        {
        }

        uint64_t ULongLiteralToken::getValue()
        {
            return _val;
        }

        bool ULongLiteralToken::isULongLiteral()
        {
            return true;
        }
        bool ULongLiteralToken::isULongLiteral(uint64_t val)
        {
            return _val == val;
        }

        string ULongLiteralToken::toString()
        {
            stringstream stream;
            stream << _val << "l";
            return stream.str();
        }
    }
}
