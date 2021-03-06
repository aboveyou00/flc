#include "stdafx.h"
#include "FloatLiteralToken.h"
#include <sstream>

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

        bool FloatLiteralToken::isFloatLiteral()
        {
            return true;
        }
        bool FloatLiteralToken::isFloatLiteral(float val)
        {
            return _val == val;
        }

        string FloatLiteralToken::toString()
        {
            stringstream stream;
            stream << _val << "f";
            return stream.str();
        }
    }
}
