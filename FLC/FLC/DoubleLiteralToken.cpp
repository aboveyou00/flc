#include "stdafx.h"
#include "DoubleLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        DoubleLiteralToken::DoubleLiteralToken(string sourceFile, int startPos, int length, double value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        DoubleLiteralToken::~DoubleLiteralToken()
        {
        }

        double DoubleLiteralToken::getValue()
        {
            return _val;
        }

        bool DoubleLiteralToken::isDoubleLiteral()
        {
            return true;
        }
        bool DoubleLiteralToken::isDoubleLiteral(double val)
        {
            return _val == val;
        }

        string DoubleLiteralToken::toString()
        {
            stringstream stream;
            stream << _val << "d";
            return stream.str();
        }
    }
}
