#include "stdafx.h"
#include "ErrorToken.h"

namespace flc
{
    namespace tokens
    {
        ErrorToken::ErrorToken(string sourceFile, int startPos, int length, string error)
            : Token(sourceFile, startPos, length)
        {
            _err = error;
        }
        ErrorToken::~ErrorToken()
        {
        }

        string ErrorToken::getError()
        {
            return _err;
        }

        string ErrorToken::toString()
        {
            return "ERROR: " + _err;
        }
    }
}
