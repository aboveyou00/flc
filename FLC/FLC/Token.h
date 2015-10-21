#pragma once
#include "stdafx.h"

namespace flc
{
    namespace tokens
    {
        class Token
        {
        public:
            Token(string sourceFile, int startPos, int length);
            ~Token();

            //integerLiteralToken, floatLiteralToken, symbolToken, stringLiteralToken, characterLiteralToken
            string getSourceFile();
            int getStartPosition();
            int getLength();
            int getEndPosition();

            virtual string toString();

        private:
            string _path;
            int _start, _length;
        };

        std::ostream& operator<<(std::ostream& o, Token& tok);
    }
}
