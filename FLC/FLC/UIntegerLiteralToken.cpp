#include "stdafx.h"
#include "UIntegerLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        UIntegerLiteralToken::UIntegerLiteralToken(string sourceFile, int startPos, int length, uint32_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        UIntegerLiteralToken::~UIntegerLiteralToken()
        {
        }

        uint32_t UIntegerLiteralToken::getValue()
        {
            return _val;
        }

        bool UIntegerLiteralToken::isUIntegerLiteral()
        {
            return true;
        }
        bool UIntegerLiteralToken::isUIntegerLiteral(uint32_t val)
        {
            return _val == val;
        }

        string UIntegerLiteralToken::toString()
        {
            stringstream stream;
            stream << _val << "u";
            return stream.str();
        }
    }
}
