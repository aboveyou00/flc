#include "stdafx.h"
#include "EndOfFileToken.h"

namespace flc
{
    namespace tokens
    {
        EndOfFileToken::EndOfFileToken(string sourceFile, int pos)
            : Token(sourceFile, pos, 0)
        {
        }
        EndOfFileToken::~EndOfFileToken()
        {
        }

        string EndOfFileToken::toString()
        {
            return "EOF";
        }
    }
}
