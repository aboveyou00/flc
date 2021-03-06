#include "stdafx.h"
#include "BooleanLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        BooleanLiteralToken::BooleanLiteralToken(string sourceFile, int startPos, bool value)
            : KeywordToken(sourceFile, startPos, value ? "true" : "false")
        {
            _val = value;
        }
        BooleanLiteralToken::~BooleanLiteralToken()
        {
        }

        bool BooleanLiteralToken::getValue()
        {
            return _val;
        }

        bool BooleanLiteralToken::isBooleanLiteral()
        {
            return true;
        }
        bool BooleanLiteralToken::isBooleanLiteral(bool val)
        {
            return _val == val;
        }
    }
}
