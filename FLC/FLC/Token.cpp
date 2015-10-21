#include "stdafx.h"
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        Token::Token(string sourceFile, int startPos, int length)
        {
            _path = sourceFile;
            _start = startPos;
            _length = length;
        }
        Token::~Token()
        {
        }

        string Token::getSourceFile()
        {
            return _path;
        }
        int Token::getStartPosition()
        {
            return _start;
        }
        int Token::getLength()
        {
            return _length;
        }
        int Token::getEndPosition()
        {
            return _start + _length;
        }

        std::ostream& operator<<(std::ostream& o, Token& tok)
        {
            o << "[" << tok.getStartPosition();
            if (tok.getLength() != 0) o << ", " << tok.getEndPosition();
            return o << ") " << tok.toString();

            //cout << tok;
            //[3,7) false
        }
    }
}
