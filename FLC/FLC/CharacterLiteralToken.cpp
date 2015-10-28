#include "stdafx.h"
#include "CharacterLiteralToken.h"
#include <sstream>

namespace flc
{
    namespace tokens
    {
        CharacterLiteralToken::CharacterLiteralToken(string sourceFile, int startPos, int length, char16_t value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        CharacterLiteralToken::~CharacterLiteralToken()
        {
        }

        char16_t CharacterLiteralToken::getValue()
        {
            return _val;
        }

        bool CharacterLiteralToken::isCharacterLiteral()
        {
            return true;
        }
        bool CharacterLiteralToken::isCharacterLiteral(char16_t val)
        {
            return _val == val;
        }

        string CharacterLiteralToken::toString()
        {
            stringstream stream;
            stream << "'" << (char)_val << "'";
            return stream.str();
        }
    }
}
