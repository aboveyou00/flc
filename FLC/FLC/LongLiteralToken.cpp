#include "stdafx.h"
#include "LongLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        LongLiteralToken::LongLiteralToken(string sourceFile, int startPos, int length, uint64_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        LongLiteralToken::~LongLiteralToken()
        {
        }

        uint64_t LongLiteralToken::getValue()
        {
            return _val;
        }

        bool LongLiteralToken::isLongLiteral()
        {
            return true;
        }
        bool LongLiteralToken::isLongLiteral(uint64_t val)
        {
            return _val == val;
        }

        string LongLiteralToken::toString()
        {
            stringstream stream;
            stream << _val << "l";
            return stream.str();
        }
    }
}
