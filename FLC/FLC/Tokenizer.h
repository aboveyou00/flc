#pragma once
#include "stdafx.h"
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class Tokenizer
        {
        public:
            Tokenizer();
            ~Tokenizer();

			vector<Token> tokenize(istream * sourceFile, string path="");
		
		private:
			Token parseNextToken(char *buffer, int startPos, string path);
			bool parseCharacterToken(char *buffer, int *length, char *c);
			bool parseFloatLiteralToken(char *buffer, int *length);
			bool parseIntegerLiteralToken(char * buffer, int * length);
			bool parseStringLiteralToken(char * buffer, int * length);
			bool parseSymbolLiteralToken(char * buffer, int * length);
			bool parseIdentifierToken(char * buffer, int * length);
			bool isWhiteSpace(char c);

        };
    }
}
