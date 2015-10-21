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
			bool endOfFile;
			Token parseNextToken(istream *source, int *index, string path);
			Token parseCharacterToken(istream *source, int *index, string path);
			Token parseNumericToken(istream *source, int *index, string path);
			Token parseStringToken(istream *source, int *index, string path);
			Token parseSymbolToken(istream *source, int *index, string path);
			Token parseIdentifierToken(istream *source, int *index, string path);
			
			bool isWhiteSpace(char c);
			char escapeSequenceToChar(string sequence);

        };
    }
}
