#include "stdafx.h"
#include "SymbolToken.h"

namespace flc
{
    namespace tokens
    {
        SymbolToken::SymbolToken(string sourceFile, int startPos, int length, string symbol)
            : Token(sourceFile, startPos, length)
        {
            _sym = symbol;
        }
        SymbolToken::~SymbolToken()
        {
        }

        string SymbolToken::getSymbol()
        {
            return _sym;
        }

        string SymbolToken::toString()
        {
            return _sym;
        }
    }
}
