#pragma once
#include <string>
#include <istream>
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

			vector<Token*>* tokenize(istream *sourceFile, string path="");
		    
		private:
			Token* parseNextToken(istream *source, int *index, string path);
			Token* parseCharacterToken(istream *source, int *index, string path);
			Token* parseNumericToken(istream *source, int *index, string path);
			Token* parseStringToken(istream *source, int *index, string path);
			Token* parseSymbolToken(istream *source, int *index, string path);
			Token* parseIdentifierToken(istream *source, int *index, string path);
			
			bool isOctal(char16_t c);
			bool isDecimal(char16_t c);
			bool isHexadecimal(char16_t c);
			bool isAlphanumeric(char16_t c);
			bool isWhiteSpace(char16_t c);

            char16_t escapeSequenceToChar(istream *source, int *length);
        };
    }
}
