#include "stdafx.h"
#include "IdentifierToken.h"
#include "BooleanLiteralToken.h"
#include "NullLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        IdentifierToken::IdentifierToken(string sourceFile, int startPos, int length, string value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        IdentifierToken::~IdentifierToken()
        {
        }

        string IdentifierToken::getValue()
        {
            return _val;
        }

        Token* IdentifierToken::getToken(string sourceFile, int startPos, int length, string value)
        {
            if (value == "true") return new BooleanLiteralToken(sourceFile, startPos, true);
            else if (value == "false") return new BooleanLiteralToken(sourceFile, startPos, false);
            else if (value == "null") return new NullLiteralToken(sourceFile, startPos);
            
            //TODO: insert other keywords here
            
            else return new IdentifierToken(sourceFile, startPos, length, value);
        }
    }
}
