#include "stdafx.h"
#include "NullLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        NullLiteralToken::NullLiteralToken(string sourceFile, int startPos)
            : KeywordToken(sourceFile, startPos, "null")
        {
        }
        NullLiteralToken::~NullLiteralToken()
        {
        }

        bool NullLiteralToken::isNullLiteral()
        {
            return true;
        }
    }
}
