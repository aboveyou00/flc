#include <sstream>
#include "stdafx.h"
#include "Tokenizer.h"
#include "CharacterLiteralToken.h"
#include "FloatLiteralToken.h"
#include "IntegerLiteralToken.h"
#include "ErrorToken.h"

namespace flc
{
    namespace tokens
    {
        Tokenizer::Tokenizer()
        {
            
        }
		Tokenizer::~Tokenizer()
		{

		}

        vector<Token> Tokenizer::tokenize(istream *sourceFile, string path)
        {
			vector<Token> *result = new vector<Token>();
			int pos = 0;
			endOfFile = false;
			while (!endOfFile) {
				Token next = parseNextToken(sourceFile, &pos, path);
				(*result).push_back(next);
				pos += next.getLength();
			}
			return *result;
        }
		
		bool Tokenizer::isWhiteSpace(char c) {
			return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
		}
		char Tokenizer::escapeSequenceToChar(string sequence) {
			// Not implemented
			return sequence[0];
		}

		Token Tokenizer::parseNextToken(istream *source, int *index, string path) {
			while (isWhiteSpace((*source).peek())) {
				index++;(*source).get();
			}
			
			char nextChar = (*source).peek();
			if (nextChar == '\'') {
				return parseCharacterToken(source, index, path);
			}
			else if (nextChar >= '0' && nextChar <= '9') {
				return parseNumericToken(source, index, path);
			}
			else if (nextChar >= 'a' && nextChar <= 'z' || nextChar >= 'A' && nextChar <= 'Z' || nextChar == '_') {
				return parseIdentifierToken(source, index, path);
			}
			else {
				return parseSymbolToken(source, index, path);
			}
		}
		Token Tokenizer::parseCharacterToken(istream *source, int *index, string path) {
			(*source).get();
			char nextChar = (*source).peek();
			if (nextChar == '\\') {
				int length = 3;
				stringstream escapeSequence;
				escapeSequence << nextChar;		// get at least one character
				while ((nextChar = (*source).get()) != '\'') {
					escapeSequence << nextChar;
					length++;
				}
				char c = escapeSequenceToChar(escapeSequence.str());
				return CharacterLiteralToken(path, *index, length, c);
			}
			else {
				char c = (*source).get();
				if ((*source).get() != '\'') {
					return ErrorToken(path, *index, 3, "Invalid char literal");
				}
				else {
					return CharacterLiteralToken(path, *index, 3, c);
				}
			}
		}
		Token Tokenizer::parseNumericToken(istream *source, int *index, string path) {
			stringstream numberString;
			int length = 0;
			bool foundDecimal = false;
			char nextChar;
			while ( (nextChar = (*source).get()) && (nextChar >= '0' && nextChar <= '9' || (nextChar == '.' && !foundDecimal)) ) {
				if (nextChar == '.')
					foundDecimal = true;
				numberString << nextChar;
				length++;
			}
			if (foundDecimal) {
				return FloatLiteralToken(path, *index, length, stof(numberString.str()));
			}
			else {
				return IntegerLiteralToken(path, *index, length, stoi(numberString.str()));
			}
		}

		Token Tokenizer::parseStringToken(istream *source, int *index, string path) {}

		Token Tokenizer::parseIdentifierToken(istream *source, int *index, string path) {}

		Token Tokenizer::parseSymbolToken(istream *source, int *index, string path) {}
    }
}
