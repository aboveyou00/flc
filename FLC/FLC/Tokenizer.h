#pragma once
#include <string>
#include <vector>
#include <istream>
#include <sstream>

namespace flc
{
    namespace tokens
    {
        class Token;

        class Tokenizer
        {
        public:
            Tokenizer();
            ~Tokenizer();

			std::vector<Token*> *tokenize(std::istream *sourceFile, std::string path="");
		    
		private:
			Token *parseNextToken(std::istream *source, int &index, std::string path);

			Token *parseCharacterToken(std::istream *source, int &index, std::string path);
			Token *parseNumericToken(std::istream *source, int &index, std::string path);
			Token *parseStringToken(std::istream *source, int &index, std::string path);
			Token *parseSymbolToken(std::istream *source, int &index, std::string path);
			Token *parseIdentifierToken(std::istream *source, int &index, std::string path);
			
			bool isOctal(char16_t c);
			bool isDecimal(char16_t c);
			bool isHexadecimal(char16_t c);
			bool isAlphanumeric(char16_t c);
			bool isWhiteSpace(char16_t c);

            char16_t escapeSequenceToChar(std::istream *source, int *length);

            bool parseComment(std::istream *source);
            
            bool parseBinaryIntegerLiteral(std::istream *source, std::stringstream *numberString);
            bool parseOctalIntegerLiteral(std::istream *source, std::stringstream *numberString);
            bool parseHexIntegerLiteral(std::istream *source, std::stringstream *numberString);
        };
    }
}
