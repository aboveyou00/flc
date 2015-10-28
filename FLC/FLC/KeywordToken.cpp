#include "stdafx.h"
#include "KeywordToken.h"

namespace flc
{
    namespace tokens
    {
        KeywordToken::KeywordToken(string sourceFile, int startPos, string value)
            : Token(sourceFile, startPos, value.length())
        {
            _val = value;
        }
        KeywordToken::~KeywordToken()
        {
        }

        string KeywordToken::getValue()
        {
            return _val;
        }

        bool KeywordToken::isKeyword()
        {
            return true;
        }
        bool KeywordToken::isKeyword(string val)
        {
            return _val == val;
        }

        string KeywordToken::toString()
        {
            return _val;
        }
    }
}
