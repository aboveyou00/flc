#include "stdafx.h"
#include "SymbolToken.h"

namespace flc
{
    namespace tokens
    {
        SymbolToken::SymbolToken(string sourceFile, int startPos, string symbol)
            : Token(sourceFile, startPos, symbol.size())
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

        bool SymbolToken::isSymbol()
        {
            return true;
        }
        bool SymbolToken::isSymbol(string sym)
        {
            return _sym == sym;
        }

        string SymbolToken::toString()
        {
            return _sym;
        }
    }
}
